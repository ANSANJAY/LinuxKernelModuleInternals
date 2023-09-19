In C Programs, we pass command line parameters through argc/argv. 

Kernel programming also allows us to pass command line parameters.

The command line parameters provides a single linux driver to do multiple things, for example

	instead of fixing to a single I/O address for read/write, it can provide that as command line argument and allow user to read/write any address. 

	Enable/disable debug logs/printk

	Allow user to set the mode if the driver supports multiple modes


=========================================
How to pass Parameters to modules?
=========================================

We can add parameters using module_param macro. Declared in moduleparam.h file

#define module_param(name, type, perm)              \
    module_param_named(name, name, type, perm)

name: name of the variable
type: Type of the Variable. Supported types are charp, bool, invbool, int, long, short, uint, ulong, ushort
perm: Permissions for the sysfs entry.  
E.g. S_IRUGO : Only read by all users
       0 : No sysfs entry
You can also use numeric values like 0644 for permission entry.



