/* $CecA1GW: , v1.1 2014/04/07 21:44:00 anders Exp $ */

/*
 * Copyright (c) 2014, Anders Franzen.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * @(#)cec.c
 */

#include "sys.h"
#include "io.h"
#include "cec_drv.h"
#include "cec.h"
#include "a1.h"

#include "asynchio.h"


static int fd_cec;
static unsigned char cec_rbuf[24];

static int distribute_msg(int itf, unsigned char *buf, int len);
static int handle_cec_data(int fd,int ev, void *dum);

struct devt {
	int bus;
	CEC_CALLBACK callback;
};

struct devt devt[16];
static int ack_mask;

#ifdef DEBUG
int cec_dump_data(int itf, char *pretext, unsigned char *buf, int len) {
        int i;
	char *itf_str=(itf==CEC_BUS)?"CEC_BUS":(itf==A1_LINK)?"A1_LINK":"USB_BUS";
        DPRINTF("from %s, %s: %x",itf_str,pretext, buf[0]);
        for(i=1;i<len;i++) {
                DPRINTF(", %02x",buf[i]);
        }
        DPRINTF("\n");
        return 0;
}
#endif

int cec_init_cec(void) {
	fd_cec=io_open(CEC_DRV);
	io_control(fd_cec,F_SETFL,(void *)O_NONBLOCK,0);
	register_event(fd_cec,EV_READ,handle_cec_data,0);
	return fd_cec;
}

int cec_attach(int itf, unsigned int la, CEC_CALLBACK callback) {
	if (!devt[la].callback) {
		devt[la].bus=itf;
		devt[la].callback=callback;
		ack_mask|=(1<<la);
		DPRINTF("installing dev %x\n", la);
		io_control(fd_cec,CEC_SET_ACK_MSK,&ack_mask,sizeof(ack_mask));
		return la;
	} else {
		DPRINTF("cant install already installed dev %x\n", la);
	}
	return -1;
}

int cec_detach(unsigned int la) {
	if (devt[la].callback) {
		devt[la].callback=0;
		ack_mask&=~(1<<la);
		DPRINTF("uninstalling dev %x\n", la);
		return io_control(fd_cec,CEC_SET_ACK_MSK,&ack_mask,sizeof(ack_mask));
	}
	return 0;
}

int cec_send_physical_address(int itf, unsigned int addr, unsigned short paddr, int function) {
	unsigned char buf[] = {addr, CEC_OPCODE_REPORT_PHYSICAL_ADDRESS, 0, 0, function};
	buf[2]=paddr>>8;
	buf[3]=paddr&0xff;
	return distribute_msg(itf,buf,sizeof(buf));
}

int cec_send_osd_name(int itf, unsigned int addr, unsigned char *idbuf) {
	unsigned char buf[16]={addr,CEC_OPCODE_SET_OSD_NAME,};
	int len=__builtin_strlen((char *)idbuf);
	__builtin_memcpy(&buf[2],idbuf,len);

	len+=2;
	return distribute_msg(itf,buf,len);
}

int cec_send_system_audio_mode_status(int itf, unsigned int addr, int on) {
	unsigned char buf[]={addr,CEC_OPCODE_SYSTEM_AUDIO_MODE_STATUS,(on)?1:0};
	return distribute_msg(itf,buf,sizeof(buf));
}

int cec_send_system_audio_mode_set(int itf, unsigned int addr, int on) {
	unsigned char buf[]={addr,CEC_OPCODE_SET_SYSTEM_AUDIO_MODE,(on)?1:0};
	return distribute_msg(itf,buf,sizeof(buf));
}


int cec_send_vendor_id(int itf, unsigned int addr,unsigned int vendor_id) {
	unsigned char *vid=(unsigned char *)&vendor_id;
	unsigned char buf[]={addr,CEC_OPCODE_DEVICE_VENDOR_ID,vid[2],vid[1],vid[0]};
	return distribute_msg(itf,buf,sizeof(buf));
}

int cec_send_power_status(int itf, unsigned int addr, int on) {
	unsigned char buf[]={addr,CEC_OPCODE_REPORT_POWER_STATUS,(on)?1:0};
	return distribute_msg(itf,buf,sizeof(buf));
}

int cec_send_active_source(int itf, unsigned int cec_addr, unsigned short paddr) {
	unsigned char buf[] = {cec_addr, CEC_OPCODE_ACTIVE_SOURCE, 0, 0};
	buf[2]=paddr>>8;
	buf[3]=paddr&0xff;

	return distribute_msg(itf,buf,sizeof(buf));
}

int cec_send_standby(int itf, unsigned int cec_addr) {
	unsigned char buf[]={cec_addr,CEC_OPCODE_STANDBY};
	return distribute_msg(itf,buf,sizeof(buf));
}

int cec_send_image_view_on(int itf, unsigned int cec_addr) {
	unsigned char buf[]={cec_addr,CEC_OPCODE_IMAGE_VIEW_ON};
	return distribute_msg(itf,buf,sizeof(buf));
}

int cec_send_cec_version(int itf, unsigned int cec_addr, unsigned char version) {
	unsigned char buf[]={cec_addr,CEC_OPCODE_CEC_VERSION,version};
	return distribute_msg(itf,buf,sizeof(buf));
}

int cec_send_abort(int itf, unsigned int cec_addr,
		unsigned char opcode, unsigned char reason) {
	unsigned char buf[]={cec_addr,CEC_OPCODE_FEATURE_ABORT,opcode,reason};
	return distribute_msg(itf,buf,sizeof(buf));
}



int cec_send(int itf, unsigned char *buf, int len) {
	if (itf==USB_BUS) {
		if ((len>1)&&(buf[1]==0x36)) {
			a1_power_off();
		}
	}
	return distribute_msg(itf,buf,len);
}

int cec_bus_send(unsigned char *buf, int len) {
	int rc;
	io_control(fd_cec,F_SETFL,(void *)0,0);
	rc=io_write(fd_cec,(char *)buf,len);
	io_control(fd_cec,F_SETFL,(void *)O_NONBLOCK,0);
	return rc;
}


static int handle_cec_data(int fd,int ev, void *dum) {
	int rc;
	int to;

	rc=io_read(fd,(char *)cec_rbuf,sizeof(cec_rbuf));
	if (rc<0) {
		return rc;
	}

	if (rc==9) {
                unsigned char sonyOn[]={0x0f,0xa0,0x08,0x00,0x46,0x00,0x04};
                if (__builtin_memcmp(cec_rbuf,sonyOn,sizeof(sonyOn))==0) {
                        /* wakeup  set top box */
			wakeup_usb_dev();

			/* Start amp */
			a1_power_on();
                }
        }

	to=cec_rbuf[0]&0xf;
	if (to==0xf) { // Broadcast
		if ((cec_rbuf[1]==CEC_OPCODE_ROUTING_CHANGE)&&(rc>=6)) {
//			unsigned int old_pa=(cec_rbuf[2]<<8)|cec_rbuf[3];
			unsigned int new_pa=(cec_rbuf[4]<<8)|cec_rbuf[5];
			if (new_pa==0x1000) {
				wakeup_usb_dev();
			}
		} else if (cec_rbuf[1]==CEC_OPCODE_SET_MENU_LANGUAGE) {
			wakeup_usb_dev();
		}
	}

	distribute_msg(CEC_BUS, cec_rbuf,rc);
	return 0;
}

int distribute_msg(int itf, unsigned char *buf, int len) {
	int to=buf[0]&0xf;
	int rc=0;
	int rc1=0;
	int found=0;

	DUMP_DATA(itf, "distribute msg", buf,len);
	if (to==0xf) { // Broadcast
		int i;

		for (i=0;i<15;i++) {
			if (devt[i].callback&&(devt[i].bus!=itf)) {
				rc=devt[i].callback(buf,len);
			}
		}
	} else {
		if (devt[to].callback&&(devt[to].bus!=itf)) {
			rc=devt[to].callback(buf,len);
			found=1;
		}
	}
	if (itf!=CEC_BUS) {
		rc1=cec_bus_send(buf,len);
	}
	if (found) {
		return rc;
	}
	return rc1;
}

int cec_set_rec(int enable) {
	DPRINTF("cec_set_rec: %d\n", enable);
	io_control(fd_cec,F_SETFL,(void *)O_NONBLOCK,0);
	return 0;
}
