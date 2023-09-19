#include <linux/module.h>
#include <linux/kernel.h>
extern struct module __this_module;
static int myinit(void)
{
    /* Set by default based on the module file name. */
    pr_info("name    = %s\n", THIS_MODULE->name);
    pr_info("version = %s\n", THIS_MODULE->version);
    pr_info("version = %s\n", (&__this_module)->version);
    return 0;
}

static void myexit(void) {}

module_init(myinit)
module_exit(myexit)
MODULE_VERSION("1.0");
MODULE_LICENSE("GPL");
