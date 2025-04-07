CROSS_C := aarch64-linux-gnu-
KERNEL_BUILD := ./rpi4-linux-kernel/
obj-m += lab_01.o

all:
	make ARCH=arm64 CROSS_COMPILE=$(CROSS_C) -C $(KERNEL_BUILD) M=$(PWD) modules

clean:
	make ARCH=arm64 CROSS_COMPILE=$(CROSS_C) -C $(KERNEL_BUILD) M=$(PWD) clean
