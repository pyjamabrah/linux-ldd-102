#include <linux/init.h>
#include <linux/module.h>
#include <asm/io.h>

MODULE_LICENSE("GPL");

void toggle_led_on(void);
void toggle_led_off(void);

static unsigned int *gpio_base = NULL;

static int __init lab_02_module_init(void) {
	printk("Welcome from Inpyjama :) \n");

	gpio_base = (unsigned int*) ioremap(0xFE200000, 4096);
	if (gpio_base == NULL) {
		printk("Error while re-mapping the io space for GPIO\n");
		return 0;
	}

	toggle_led_on();
	return 0;
}

static void __exit lab_02_module_exit(void) {
	printk("Exiting from the module \n");
	toggle_led_off();
	iounmap(gpio_base);
}

void toggle_led_on(void) {
	unsigned int temp_value = *(unsigned int *)((char *)gpio_base + 0x8);
	temp_value |= (1 << 3);
	*(unsigned int *)((char *)gpio_base + 0x8) = temp_value;

	temp_value = *(unsigned int *)((char *)gpio_base + 0x1c);
	temp_value |= (1 << 21);
	*(unsigned int *)((char *)gpio_base + 0x1c) = temp_value;
	return;
}

void toggle_led_off(void) {
	unsigned int temp_value = *(unsigned int *)((char *)gpio_base + 0x28);
	temp_value |= (1 << 21);
	*(unsigned int *)((char *)gpio_base + 0x28) = temp_value;
	return;
}

module_init(lab_02_module_init);
module_exit(lab_02_module_exit);
