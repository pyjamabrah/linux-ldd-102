#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int __init diy01_module_init(void) {
	printk("Welcome from Pyjamabrah :) \n");
	return 0;
}

static void __exit diy01_module_exit(void) {
	printk("Exiting from the module \n");
}

module_init(diy01_module_init);
module_exit(diy01_module_exit);
