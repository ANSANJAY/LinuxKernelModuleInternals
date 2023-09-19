=======================
What is Symbol
=======================

A symbol is a name given to a space in the memory which stores

	data (Variables, For reading and writing)
	instructions (Functions, for executing)

So symbol in the programming language is either a variable or function.

==========================
What is Symbol table?
==========================

Data Structure created by compiler containing all the symbols used in the program.

Every kernel image that you build has a symbol table with it. 

The Linux kernel symbol table contains names and addresses of all the kernel symbols. 

When you install the kernel it will be present in /boot/System.map-<linux_version>

=============================
How to Export your symbols?
=============================

When you define a new function in your module, the default behavior of this function is local, only the module in which the function is defined can access it, cannot be accessed by other modules.

To export this module we need to use EXPORT_SYMBOL or EXPORT_SYMBOL_GPL.

Once you export them, they will be available to other modules to use.

======================================================
Difference between EXPORT_SYMBOL and EXPORT_SYMBOL_GPL
======================================================

EXPORT_SYMBOL: The exported symbol can be used by any kernel module
EXPORT_SYMBOL_GPL: The exported symbol can be used by only GPL licensed code.


=========================================================
What is the difference between System.map and /proc/kallsyms?
=============================================================

/proc/kallsyms: Contains symbols of dynamically loaded modules as well as builtin modules
System.map: Contains symbols of only builtin modules.

$cat /boot/System.map-* | grep ttyprintk_exit

$cat /proc/kallsyms | grep ttyprintk_exit


