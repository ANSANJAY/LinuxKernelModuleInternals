**Section 1: Explain the technical concept**

📚 **GCC Attribute `alias`**:

The GNU Compiler Collection (GCC) provides several attributes that allow developers to customize how their code is compiled and linked. One such attribute is `alias`, which is particularly useful for providing alternative names (or aliases) for symbols, such as functions or variables.

Using the `alias` attribute, one can make `symbol_B` an alias to `symbol_A`. This means that, in the binary code, references to `symbol_B` will resolve to `symbol_A`.

**Syntax**:
```c
__attribute__((alias("original_symbol_name")))
```

**Example**:
```c
void original_function() {
    // some code here
}

void __attribute__((alias("original_function"))) alias_function;
```

In this example, `alias_function` is an alias for `original_function`. Any calls to `alias_function` will redirect to `original_function`.

---

**Section 2: Technical Interview Questions & Answers**

❓ **Question 1**: What is the primary use of the `alias` attribute in GCC?

📝 **Answer**: The `alias` attribute in GCC is used to specify alternative names (or aliases) for symbols, allowing developers to reference a function or variable using different names. This can be particularly useful for maintaining backward compatibility or providing different symbol names for different use cases.

❓ **Question 2**: Can an alias symbol have its own definition separate from the original symbol?

📝 **Answer**: No, an alias symbol doesn't have its own separate definition. It merely provides a new name that points to the original symbol's definition. When you reference the alias, it redirects to the original symbol.

❓ **Question 3**: How would you declare an alias for a global variable named `globalVar` with the alias name `gVar`?

📝 **Answer**: You would use the following declaration:
```c
extern int globalVar;
int __attribute__((alias("globalVar"))) gVar;
```

---

**Section 3: Simplify the concept**

🌟 **In Simple Words**:

Imagine you have a popular café named "Coffee Central". As time goes on, you decide to also refer to your café as "CC" for short, especially for some branding or marketing purposes. Now, "CC" isn't a separate café but just another name for "Coffee Central". If someone wants to visit "CC", they're essentially visiting "Coffee Central".

Similarly, in GCC, using the `alias` attribute, you can give a function (like our café) another name without creating a whole new function. When someone uses this new name in code, they're still accessing the original function. ☕👍


----


GCC Attribute alias allows you to specify multiple aliases(other names) for a symbol (function/variable).

