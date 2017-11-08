obj-m += hello_mod.o  
CURRENT_PATH := $(shell pwd)  
LINUX_KERNEL := $(shell uname -r)  
LINUX_KERNEL_PATH := /usr/src/linux-headers-$(LINUX_KERNEL)  
all:  
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) modules  
clean:  
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) clean  
install:  
	insmod hello_mod.ko  
unistall:  
	rmmod hello_mod 
