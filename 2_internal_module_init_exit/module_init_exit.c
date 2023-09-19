#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
int init_module(void)
{
    printk(KERN_INFO"%s: In init\n", __func__);
    return 0;
}

void cleanup_module(void)
{
    printk(KERN_INFO"%s: In exit\n", __func__);
}
