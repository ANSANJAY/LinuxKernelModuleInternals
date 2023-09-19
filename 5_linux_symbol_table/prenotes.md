**Section 1: Explain the technical concept**

📘 **Symbol**:

In the realm of programming, a **symbol** refers to an identifier that stands for either data storage (like variables) or sequences of instructions to execute (like functions). Symbols are essentially names given to these particular memory addresses so we can easily reference and manipulate them.

📘 **Symbol Table**:

A **symbol table** is a specialized data structure crafted by the compiler, storing a list of all the symbols utilized in a given program. For the Linux kernel, every built image has an accompanying symbol table. This table is typically found at `/boot/System.map-<linux_version>`, giving you a map of all the kernel symbols' names and their corresponding memory addresses.

📘 **Exporting Symbols**:

In the Linux kernel, when a new function or variable is declared within a module, it remains local to that module by default. To make it accessible to other modules, you need to **export** it. You have the option to use either `EXPORT_SYMBOL` or `EXPORT_SYMBOL_GPL` based on licensing needs.

📘 **Difference between EXPORT_SYMBOL and EXPORT_SYMBOL_GPL**:

- `EXPORT_SYMBOL`: Allows any kernel module, irrespective of its licensing, to use the exported symbol.
  
- `EXPORT_SYMBOL_GPL`: Restricts usage of the exported symbol only to modules that are GPL licensed.

📘 **Difference between System.map and /proc/kallsyms**:

- **System.map**: This is a symbol table that contains symbols only for the kernel's built-in modules.
  
- **/proc/kallsyms**: This contains symbols for both the kernel's built-in modules and the dynamically loaded modules. It provides a broader view of symbols present in the running kernel.

---

**Section 2: Technical Interview Questions & Answers**

❓ **Question 1**: Why might a developer choose to use `EXPORT_SYMBOL_GPL` over `EXPORT_SYMBOL`?

📝 **Answer**: A developer might use `EXPORT_SYMBOL_GPL` to ensure that the exported symbol is only used by modules that adhere to the GPL license. This can help in maintaining the open-source ethos and prevent proprietary modules from utilizing certain critical or sensitive functionalities.

❓ **Question 2**: How can one symbol be present in both `System.map` and `/proc/kallsyms`? 

📝 **Answer**: A symbol will appear in both `System.map` and `/proc/kallsyms` if it's part of the kernel's built-in modules. While `System.map` only contains built-in module symbols, `/proc/kallsyms` includes those along with symbols from dynamically loaded modules.

❓ **Question 3**: What happens if two modules export the same symbol name?

📝 **Answer**: If two modules try to export the same symbol name, it will lead to a conflict. When you try to insert the second module that exports the already exported symbol, the kernel will prevent it from being loaded, and an error will be reported.

---

**Section 3: Simplify the concept**

💡 **In Simple Words**:

Imagine you're in a library 📚:

1. **Symbols**: Think of symbols as the titles of books and journals. Each title represents a specific set of information (data or instructions).

2. **Symbol Table**: This is like the library's catalog system, listing all the titles available and where to find them.

3. **Exporting Symbols**: Suppose you've written a new book and want to make it available to others. Exporting is like adding your book to the library's collection, so others can read it. But you can choose who gets to read it: everyone (`EXPORT_SYMBOL`) or only those with a special membership (`EXPORT_SYMBOL_GPL`).

4. **System.map vs. /proc/kallsyms**: It's like having two catalog systems. One (`System.map`) only lists the permanent collection of the library, while the other (`/proc/kallsyms`) lists both the permanent collection and the new arrivals or temporary exhibits.



------

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


