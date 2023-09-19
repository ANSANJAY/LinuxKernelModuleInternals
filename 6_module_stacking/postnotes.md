Build the modules by running "make", Load the first module and then second module using insmod.

To use modprobe
========================

sudo ln -s /<givefullpath>/module1.ko  /lib/modules/$(uname -r)/kernel/drivers/misc
sudo ln -s /<givefullpath>/module2.ko  /lib/modules/$(uname -r)/kernel/drivers/misc

sudo depmod -a

sudo modprobe module2

check lsmod, module1 should automatically be loaded.



