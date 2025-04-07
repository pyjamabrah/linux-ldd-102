CROSS_C := aarch64-linux-gnu-
KERNEL_BUILD := ../rpi4-linux-kernel/
obj-m += lab_01.o

all:
	make ARCH=arm64 CROSS_COMPILE=$(CROSS_C) -C $(KERNEL_BUILD) M=$(PWD) modules
	@echo "Zipping Kernel Image and the .ko"
	@zip -j kernel-module.zip ../rpi4-linux-kernel/arch/arm64/boot/Image lab_01.ko > /dev/null
	@echo "Done! please download and extract and place the files in their corresponding location"

clean:
	make ARCH=arm64 CROSS_COMPILE=$(CROSS_C) -C $(KERNEL_BUILD) M=$(PWD) clean
	rm -rf *.zip
