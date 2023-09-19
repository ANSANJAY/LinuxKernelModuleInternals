Overview of compiling Kernel Modules
======================================

kernel use  kbuild system to build the kernel modules

kbuild system reads  the assignment of "obj-m := modulename.o"  from the makefile. 

Now the kbuild system know that it has to build "modulename.ko" and will look for "modulename.c" for the source.

 In case these files are not present in the directory passed to "M" , the compiling will stop with an error. 

If the files are present the source file is compiled to a "modulname.o",  and "modulename.mod.c" is created which is compiled to "modulename.mod.o". 

The modulename.mod.c is a file that basically contains the information about the module (Version information etc).

The modulename.o and the modulename.mod.o are linked together by modpost in the next stage to create the "modulename.ko" 

Other Files
============

"module.symvers": This will contain any of external symbols that is defined in your module and hence not present in the module.symvers of the kernel .

"modules.order" : In case you are compiling multiple modules together, it will list out the order in which the compilation and creation of .ko takes 



