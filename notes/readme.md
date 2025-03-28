# templates

## introduction
+ Templates in C++ allow generic programming, enabling code to be written once and used with different data types without rewriting it. They are widely used in functions and classes to improve reusability and type safety.
+ Pros
  + Code Reusability: Write once, use with different data types.
  + Type Safety: Compiler checks types at compile time.
  + Performance: No runtime overhead (unlike void*-based generic programming).
+ Cons
  + Code Bloat: A separate version of the function/class is generated for each type used.
  + Longer Compilation Times: More templates mean more compile-time processing.
  + Harder Debugging: Errors in templates can be cryptic.

To have in mind:
+ function templates
+ class templates
+ template specialization (when a specilized implementation is needed for a type)
+ non-type template parameters: templates can accept values (not just types)
+ variadic templates (in c++11 and later)

```c++

// function template
template<typename T>
T	const &min(T const &x, T const &y)
{
	return (x <= y ? x : y);
}


```

+ `template <typename T>` to initialize the T type, it could have any name
+ it's the way we tell the compiler it's a generatic type
+ we pass parameters by ref to save memory, and we put const beacuse we dont,modify the values
  
## templates



## default type



## specialization



## conclusion



## from c -  parametric macros


