
To pass multiple parameters we need to pass parameter array. 

To pass array we need to use module_param_array() function instead of module_param() function

#define module_param(name, type, perm)


 * module_param_array - a parameter which is an array of some type
 * @name: the name of the array variable
 * @type: the type, as per module_param()
 * @nump: optional pointer filled in with the number written
 * @perm: visibility in sysfs


#define module_param_array(name, type, nump, perm) 


sudo insmod ./parameter_array.ko param_array=1,2,4
