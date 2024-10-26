/*
SFINAE stands for "Substitution Failure Is Not An Error." 
It is a principle in C++ template metaprogramming that allows for a technique called "enable_if" 
to conditionally enable or disable template functions or classes based on certain compile-time conditions. 
SFINAE is a powerful mechanism that leverages the template substitution process to control the instantiation and selection of template functions.

In C++, when a template function is called with specific arguments, 
the compiler attempts to substitute the function template's parameters with the provided arguments. 
If the substitution fails, instead of generating a compilation error, the compiler continues to search for alternative function templates or overload candidates. 
This behavior is where the principle gets its name—substitution failure is not considered an error.
*/

#include <type_traits>
using namespace as std

// Function template with enable_if
template <typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
printNumber(T number) {
    std::cout << "Integral number: " << number << std::endl;
}

// Function template overload without enable_if
template <typename T>
typename std::enable_if<!std::is_integral<T>::value, void>::type
printNumber(T number) {
    std::cout << "Non-integral number: " << number << std::endl;
}

int main() {
    printNumber(10);  // Calls the first overload
    printNumber(3.14);  // Calls the second overload
    return 0;
}


/*
SFINAE and enable_if are widely used techniques in C++ template metaprogramming to create more flexible 
and customizable code, enabling compile-time branching based on type traits, concepts, or other compile-time conditions. 
They allow for the creation of more specialized template functions and better control over template overload resolution.
*/