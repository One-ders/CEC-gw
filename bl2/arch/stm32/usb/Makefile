
DRV_NAME=usb_drv
OBJS=usb_core.o usb_device.o usb_dev_core.o bsp_usb_otg.o

SYS_INC=$(TOP)/incl
SYS_LIB=$(OBJ)/lib

#AS=arm-none-eabi-as
#CC=arm-none-eabi-gcc
##CFLAGS=-g -O2 -DDEBUG -DDRIVERSUPPORT -DUNECESS -Wall -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork -mfloat-abi=hard -mfpu=fpv4-sp-d16 -fno-builtin -I$(SYS_INC)
#CFLAGS=-g -O2 -DDEBUG -DDRIVERSUPPORT -DUNECESS -Wall -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork -mfloat-abi=soft -fno-builtin -I$(SYS_INC)
#LDFLAGS=-g -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork -fno-builtin


all: $(SYS_INC) $(SYS_INC)/usb_device.h $(SYS_INC)/usb_core.h $(SYS_LIB) $(SYS_LIB)/$(DRV_NAME).o

$(SYS_INC):
	mkdir $@

$(SYS_LIB):
	mkdir $@

$(SYS_INC)/usb_device.h: usb_device.h
	cp $^ $@

$(SYS_INC)/usb_core.h: usb_core.h
	cp $^ $@

$(SYS_LIB)/$(DRV_NAME).o: $(DRV_NAME).o
	cp $^ $@

$(DRV_NAME).o: $(OBJS)
	$(CC) -r -nostdlib -o $@ $(OBJS)



drv_clean:
	rm -rf *.o
