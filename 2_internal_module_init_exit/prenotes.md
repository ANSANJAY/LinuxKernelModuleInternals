We know on insmod, the function passed in the module_init macro is called, and on rmmod, the argument passed in the module_exit is called.

Let's see the definition of this macro, it is present in linux/module.h

/* Each module must use one module_init(). */
#define module_init(initfn)                 \
    static inline initcall_t __inittest(void)       \
    { return initfn; }                  \
    int init_module(void) __attribute__((alias(#initfn)));

/* This is only required if you want to be unloadable. */
#define module_exit(exitfn)                 \
    static inline exitcall_t __exittest(void)       \
    { return exitfn; }                  \
    void cleanup_module(void) __attribute__((alias(#exitfn)));

The purpose of defining __inittest function is to check during compile time, the function passed to module_init() macro is compatible with the initcall_t type.

initcall_t is defined in linux/init.h:
typedef int (*initcall_t)(void);

If you declare module_init function which returns void instead of int, the compiler will throw warning:

The last line uses the alias attribute of gcc to assign another name to init_module, so that you can have a better name as per your driver (e.g. cdrom_init instead of init_module), instead of each driver having init_module. 

Same is the case with module_exit, giving whatever name in module_exit as parameter to cleanup_module.
