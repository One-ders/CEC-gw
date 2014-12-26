/* $FrameWorks: , v1.1 2014/04/07 21:44:00 anders Exp $ */

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
 * @(#)sys_tasklib.c
 */
#include "io.h"
#include "sys.h"

#define SVC_CREATE_TASK 1
#define SVC_SLEEP       2
#define SVC_SLEEP_ON    3
#define SVC_WAKEUP      4
#define SVC_IO_OPEN     5
#define SVC_IO_READ     6
#define SVC_IO_WRITE    7
#define SVC_IO_CONTROL  8
#define SVC_IO_CLOSE    9
#define SVC_IO_SELECT   10
#define SVC_KILL_SELF   11
#define SVC_BLOCK_TASK  12
#define SVC_UNBLOCK_TASK 13
#define SVC_SETPRIO_TASK 14
#define SVC_SETDEBUG_LEVEL 15
#define SVC_REBOOT	16
#define SVC_GETTIC	17

#include <string.h>

struct sel_args {
	int nfds;
	fd_set *rfds;
	fd_set *wfds;
	fd_set *stfds;
	unsigned int *tout;
};

struct task_create_args {
	void *fnc;
	void *val;
	unsigned int val_size;
	int prio;
	char *name;
};


/*
 *    Task side library calls
 */

/*
 * Inline assembler helper directive: call SVC with the given immediate
 */
#define svc(code) asm volatile ("svc %[immediate]\n\t"::[immediate] "I" (code))
 
/*
 * Use a normal C function, the compiler will make sure that this is going
 * to be called using the standard C ABI which ends in a correct stack
 * frame for our SVC call
 */

int svc_create_task(struct task_create_args *ta);
int svc_sleep(unsigned int);
int svc_io_open(const char *);
int svc_io_read(int fd, void *b, int size);
int svc_io_write(int fd, const void *b, int size);
int svc_io_control(int fd, int cmd, void *b, int s);
int svc_io_close(int fd);
int svc_io_select(struct sel_args *sel_args);
int svc_block_task(char *name);
int svc_unblock_task(char *name);
int svc_setprio_task(char *name, int prio);
int svc_set_debug_level(unsigned int dbglev);
int svc_reboot(unsigned int cookie);
unsigned int svc_gettic(void);


__attribute__ ((noinline)) int svc_create_task(struct task_create_args *ta) {
	register int rc asm("r0");
	svc(SVC_CREATE_TASK);
	return rc;
}


__attribute__ ((noinline)) int svc_kill_self() {
	svc(SVC_KILL_SELF);
	return 0;
}


__attribute__ ((noinline)) int svc_sleep(unsigned int ms) {
	register int rc asm("r0");
	svc(SVC_SLEEP); 
	return rc;
}

__attribute__ ((noinline)) int svc_io_open(const char *name) {
	register int rc asm("r0");
	svc(SVC_IO_OPEN);
	return rc;
}

__attribute__ ((noinline)) int svc_io_read(int fd, void *b, int size) {
	register int rc asm("r0");
	svc(SVC_IO_READ);
	return rc;
}

__attribute__ ((noinline)) int svc_io_write(int fd, const void *b, int size) {
	register int rc asm("r0");
	svc(SVC_IO_WRITE);
	return rc;
}

__attribute__ ((noinline)) int svc_io_control(int fd, int cmd, void *b, int s) {
	register int rc asm("r0");
	svc(SVC_IO_CONTROL);
	return rc;
}

__attribute__ ((noinline)) int svc_io_close(int fd) {
	register int rc asm("r0");
	svc(SVC_IO_CLOSE);
	return rc;
}

__attribute__ ((noinline)) int svc_io_select(struct sel_args *sel_args) {
	register int rc asm("r0");
	svc(SVC_IO_SELECT);
	return rc;
}

__attribute__ ((noinline)) int svc_block_task(char *name) {
	register int rc asm("r0");
	svc(SVC_BLOCK_TASK);
	return rc;
}

__attribute__ ((noinline)) int svc_unblock_task(char *name) {
	register int rc asm("r0");
	svc(SVC_UNBLOCK_TASK);
	return rc;
}

__attribute__ ((noinline)) int svc_setprio_task(char *name, int prio) {
	register int rc asm("r0");
	svc(SVC_SETPRIO_TASK);
	return rc;
}

__attribute__ ((noinline)) int svc_set_debug_level(unsigned int dbglev) {
	register int rc asm("r0");
	svc(SVC_SETDEBUG_LEVEL);
	return rc;
}

__attribute__ ((noinline)) int svc_reboot(unsigned int cookie) {
	register int rc asm("r0");
	svc(SVC_REBOOT);
	return rc;
}

__attribute__ ((noinline)) unsigned int svc_gettic(void) {
	register int rc asm("r0");
	svc(SVC_GETTIC);
	return rc;
}


/****************************************************************/

int thread_create(void *fnc, void *val, unsigned int val_size,
		int prio, char *name) {
	struct task_create_args tc_args;
	tc_args.fnc=fnc;
	tc_args.val=val;
	tc_args.val_size=val_size;
	tc_args.prio=prio;
	tc_args.name=name;

	return svc_create_task(&tc_args);
}


int sleep(unsigned int ms) {
	return svc_sleep(ms);
}

int block_task(char *name) {
	return svc_block_task(name);
}

int unblock_task(char *name) {
	return svc_unblock_task(name);
}

int setprio_task(char *name,int prio) {
	return svc_setprio_task(name,prio);
}

int set_debug_level(unsigned int dbglev) {
	return svc_set_debug_level(dbglev);
}

int _reboot_(unsigned int cookie) {
	return svc_reboot(cookie);
}

unsigned int get_current_tic(void) {
	return svc_gettic();
}





/**********************************************************************/
/*  Driver service calls                                              */

int io_open(const char *drvname) {
	return svc_io_open(drvname);
}

int io_read(int fd, void *buf, int size) {
	return svc_io_read(fd,buf,size);
}

int io_write(int fd, const void *buf, int size) {
	return svc_io_write(fd,buf,size);
}

int io_control(int fd, int cmd, void *d, int sz) {
	return svc_io_control(fd,cmd,d,sz);
}

int io_close(int fd) {
	return svc_io_close(fd);
}

int io_select(int nfds, fd_set *rfds, fd_set *wfds, fd_set *stfds, unsigned int *tout) {
	struct sel_args sel_args;
	sel_args.nfds=nfds;
	sel_args.rfds=rfds;
	sel_args.wfds=wfds;
	sel_args.stfds=stfds;
	sel_args.tout=tout;
//	printf("io_select: nfds=%d, rfds=%x, wfds=%x, stfds=%x, tout=%x\n",
//			nfds,rfds,wfds,stfds,tout);
	return svc_io_select(&sel_args);
}

