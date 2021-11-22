#Cross compilation Makefile for ARM kernel modules
# Modify KERN_SRC appropriately
KERN_SRC=~/Documents/EMBed/Lab3/linux-5.9.1
obj-m = hello_world_module.o

all: 
	make -C $(KERN_SRC) ARCH=arm CROSS_COMPILE=arm-linux-gnueabi-  M=$(PWD) modules

clean:
	make -C $(KERN_SRC) ARCH=arm CROSS_COMPILE=arm-linux-gnueabi-  M=$(PWD) clean




