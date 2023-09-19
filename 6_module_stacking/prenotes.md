==============================
What is module stacking?
==============================

New modules using the symbols exported by old modules.


==============================================
Examples of modules stacking in Linux Kernel?
=============================================

Msdos filesystem relies on symbols exported by fat module

Parallel port printer driver (lp) relies on symbols exported by generic parallel port driver (parport)

=========================
Example
=========================
1. Write module which exports a function myadd performing addition of two numbers:
2. write another module which uses the exported function
