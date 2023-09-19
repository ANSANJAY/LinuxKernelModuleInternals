===============================
How to pass parameters
===============================

sudo insmod ./argument.ko name="EMBED" loop_count=5


Let's find out what will happen when we pass wrong parameters, if I pass string in loop_count.

======================================================
How to find out the values of already loaded modules
======================================================

$ cat /sys/modules/<module_name>/parameters/<parameter_name>

This is only possible, if the permission field in the module_param macro is not zero.

=====================================================
How can we pass arguments to modules which are builtin?
=====================================================

Module parameters for builtin modules are passed through kernel command line. 

Syntax: <module_name>.<parameter_name>=value
So, if the argument module was builtin, we can append argument.loop_count=5 to the kernel command line for passing 5 as loop_count

=======================================================
How can we pass arguments which are called by modprobe?
=======================================================

modprobe reads /etc/modprobe.conf file for parameters.





