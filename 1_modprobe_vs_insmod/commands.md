lsmod – List Modules that Loaded Already

insmod – Insert Module into Kernel

modinfo – Display Module Info

rmmod – Remove Module from Kernel

modprobe – Add or Remove modules from the kernel

============================================================
insmod vs modprobe
============================================================

insmod:		Loads the module given 'insmod /path/to/module.ko'
modprobe:	Loads the module only in /lib/modules/$(uname -r) 'modprobe /home/test/hello.ko' will not work

insmod:		Dependencies if present are not loaded
modprobe:	modprobe calculates dependencies, loads the dependencies and then the main module

===============================================
How modprobe calculates dependencies?
===============================================

Modprobe depends on depmod tool to calculate dependencies.
depmod calculates dependencies of all the  modules present in /lib/modules/$(uname -r) folder, and places the dependency information in /lib/modules/$(uname -r)/modules.dep file

E.g. kernel/drivers/net/wireless/admtek/adm8211.ko: kernel/net/mac80211/mac80211.ko kernel/net/wireless/cfg80211.ko      kernel/drivers/misc/eeprom/eeprom_93cx6.ko

When you say modprobe adm8211.ko, eeprom_93cx6.ko, cfg80211.ko is loaded first and then adm8211.ko

Modules are loaded right  to left and removed left to right

So while removing adm8211.ko is removed, then cfg80211.ko and finally eeprom_93cx6.ko

We can re-load the modules.dep file by running "depmod -a" command



