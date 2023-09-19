
**Section 1: Explain the technical concept**

📚 **Passing Parameters to Kernel Modules**:

1. **Inserting Modules with Parameters**:
   Using the `insmod` command, parameters can be passed to a module during insertion. For instance:
   ```
   sudo insmod ./argument.ko name="EMBED" loop_count=5
   ```
   If you pass the wrong data type, for instance, a string to `loop_count` which expects an integer, you'll typically get an error.

2. **Checking Parameter Values of Loaded Modules**:
   The `/sys` filesystem provides a mechanism to access details of modules. To find out the value of a parameter for a loaded module:
   ```
   cat /sys/modules/<module_name>/parameters/<parameter_name>
   ```
   This works if the `perm` attribute in the module's `module_param` macro is set to a non-zero value, allowing sysfs visibility.

3. **Passing Parameters to Builtin Modules**:
   Builtin modules (modules integrated into the kernel) receive parameters through the kernel command line during boot-up. The syntax is:
   ```
   <module_name>.<parameter_name>=value
   ```

4. **Passing Parameters via Modprobe**:
   `modprobe` is a tool that adds or removes modules, considering dependencies. It can be configured to pass parameters to modules by reading configurations from `/etc/modprobe.conf` or files in `/etc/modprobe.d/`.

---

**Section 2: Technical Interview Questions & Answers**

❓ **Question 1**: What's the difference between a builtin module and an external module?

📝 **Answer**: A builtin module is integrated into the kernel binary, meaning it loads and runs automatically during system boot-up. An external module, on the other hand, is separate from the kernel binary and can be loaded or unloaded as needed using commands like `insmod` or `rmmod`.

❓ **Question 2**: What would happen if you pass an incorrect data type as a parameter value when loading a module using `insmod`?

📝 **Answer**: If you pass an incorrect data type for a module parameter using `insmod`, the kernel will typically throw an error indicating an unrecognized or inappropriate parameter value.

❓ **Question 3**: Why might you need to pass parameters to a module using `modprobe` instead of `insmod`?

📝 **Answer**: `modprobe` is intelligent and can automatically handle module dependencies. When you load a module that relies on other modules, `modprobe` will load all necessary dependencies first. Passing parameters using `modprobe` allows you to set configurations while also ensuring all dependent modules are properly loaded.

---

**Section 3: Simplify the concept**

🌟 **In Simple Words**:

Imagine building a toy 🚂 train set. 

1. **Inserting Modules with Parameters**: It's like adding a new train car with specific features, like a horn sound or a light. If you try to add a feature the car doesn't support, it won't work!

2. **Checking Parameter Values**: This is similar to checking the settings of a specific train car, like seeing if its light is on or off.

3. **Builtin Modules**: Some train cars are always attached and come as part of the train set. Changing their features requires adjusting the main train controls.

4. **Modprobe**: Imagine a master control that knows exactly which cars need to be connected and in what order, and it can also set their features at the same time!

So, with these tools, you have the flexibility to customize your train set (or module) just the way you like! 🚂🛤️

-------------------
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





