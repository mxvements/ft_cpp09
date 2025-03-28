# templates

## introduction

## templates

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

// template structs and classes
template<typename G>
class List {
	private:
		G		*_content;
		List<G>	*_next;
	public:
		List<G>( T const &content){
			// etc...
		}

		List<G>(List<G> const & list){
			// etc...
		}
		~List<G>(void){
			// etc..
		}
		// etc...
}

```

+ `template <typename T>` to initialize the T type, it could have any name
+ it's the way we tell the compiler it's a generatic type
+ we pass parameters by ref to save memory, and we put const beacuse we dont,modify the values
+ the template function, defined in a header file, is not an usable function. In order for it to be usable, it needs to be instanciated.

## default type

+ its possible to define default values for our type variables

```c++
//default type -> if we dont say otherwise, the compiler will use float
template<typename T = float>
class Vertex {
	private:
		T const _x;
		T const _y;
		T const _z;
		Vertex(void);
	public:
		Vertex (T const &x, T const &y, T const &z): _x(x), _y(y), _z(z) { }
		~Vertex(void){ }
		T const &getX(void) const { return this->_x; }
		T const &getY(void) const { return this->_y; }
		T const &getZ(void) const { return this->_z; }

}
//declaration of the << overload as template
template<typename T>
std::ostream &operator<<(std::ostream &os, Vertex<T> const &v){
	std::cout.precision(1) ;
	os << setiosflags(std::ios::fixed):
	os << v.getX() << ", ";
	os << v.getY() << ", ";
	os << v.getZ() << ", ";
	return os;
}

// when instantiating the class
Vertex<int>(12, 25, 34);
Vertex<>(12, 25, 37) //will be converted into floats
```

## specialization

+ kind of a overload of a function

```c++
//default type -> if we dont say otherwise, the compiler will use float
template<typename T, typename U>
class Pair{
	private:	
		T const	&_lhs;
		U const &_rhs;
		Pair<T,U>(void){}
	public:
		Pair<T, U>(T const &lhs, U const &rhs) : _lhs(lhs), _rhs(rhs) {
			std::cout << "Generic template" << std::endl;
			return ;
		}

		~Pair<T,U>(void) {}
		T const &lhs(void) const { return this->_lhs; }
		U const &rhs(void) const { return this->_rhs; }
}

//partial specialization
template<typename U>
class Pair<int, U>{
	private:	
		int const	_lhs;
		U const 	&_rhs;
		Pair<int,U>(void){}
	public:
		Pair<int, U>(int const lhs, U const &rhs) : _lhs(lhs), _rhs(rhs) {
			std::cout << "Generic template" << std::endl;
			return ;
		}

		~Pair<int,U>(void) {}
		int const lhs(void) const { return this->_lhs; }
		U const &rhs(void) const { return this->_rhs; }
}

//full specialization
template<>
class Pair<bool, bool>{
	private:	
		int	_n;
		Pair<bool, bool>(void){}
	public:
		Pair<bool, bool>(bool const lhs, bool const rhs) {
			std::cout << "Generic template" << std::endl;
			this->n = 0;
			//n stores bool as 2 bytes in the int
			this->_n |= static_cast<int>(lhs) << 0; // Store lhs in bit 0
        	this->_n |= static_cast<int>(rhs) << 1; // Store rhs in bit 1
			return ;
		}

		~Pair<bool, bool>(void) {}
		bool const lhs(void) const { return (this->_n & 0x01); }
		bool  const rhs(void) const { return (this->_n & 0x02); }
}
```

## conclusion


## from c -  parametric macros

+ `#` preprocessor instruction prefix

```c
#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))  // Returns the maximum of a and b

int main() {
    int x = 10, y = 20;
    printf("Max: %d\n", MAX(x, y));  // Expands to ((10) > (20) ? (10) : (20))

    return 0;
}

//there are some edge cases if we pass things like:

int foo(int x ){ printf("very long computation" ; return x; )}

int main() {
    int x = 10, y = 20;
    printf("Max: %d\n", MAX(foo(x), foo(y)));  // Expands to (foo(10) > foo(20) ? foo(10) : foo(20)) -> edge case! computing time DOUBLED

    return 0;
}

```