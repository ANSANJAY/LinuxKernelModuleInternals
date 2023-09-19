===========================
THIS_MODULE
==========================

Whenever you create a kernel module, the kernel's build machinery generates a struct module object for you, and makes THIS_MODULE point to it.

This struct contains many fields, some of which can be set with module macros such as MODULE_VERSION.

#ifdef MODULE
extern struct module __this_module;
#define THIS_MODULE (&__this_module)
#else
#define THIS_MODULE ((struct module *)0)
#endif

