# Homework 3 CMSI 386 Written Exercises

## Problem 1.

&A[0][0] = 0x7fffda007c50
&A[3][7] = 0x7fffda007d78

 This shows that the array of structs is declared beginning at memory location 0x7fffda007c50 with a size of 8, and each subsequent array element has a size of 8 leading to increments of 8 for each element. For 37 increments, an increment of 296 spaces lead to the address of A[3][7].

## Problem 2.

double \*a[n]
    
*This declaration refers to the referent of the pointer a[n]*
 
double (\*b)[n]
    
*This declaration means that b is a pointer to an array. The star operator refers to the referent of the array pointed to by b with n elements  \*b*

double (\*c[n])();
    
*This declaration is a function declaration that means that c[n] is a pointer to a function that takes in no arguments *c[n]()*
 double (\*d())[n];
    
* This declaration means the function d() is a pointer to an array of n elements in which (*d())[n] is the referent to an array with n elements.*

## Problem 3
    
f is a pointer that is of type function that takes in two arguments (double (\*)(double, double[]), double)) which is a referent to the value pointed to by the function (double, double[]) and another double. \*f, which is the value pointed to by f, is also a function that takes in a double and the rest of the arguments determined by the ... operator.

## Problem 4
    
In the Derived class, there are two b fields, the b field in the subclass is accessible within the scope of the inner subclass, and hides the b field of the outer Base class

## Problem 5
Output:

    2
    5
    2
    
Yes, these answers are the same when applying the rule of static scoping. Since x is defined outside of function g first as 2, it is first output when function f is called which prints x. Function g then declares x within its scope to be 5. Then the x declares within the scope of function g, which is 5, is output following calling function f which outputs the x declared outside the scope of function f. Finally, the x declared outside the scope of g is printed again following the call to function g, resulting in the final output above.

If C++ utilized dynamic scoping, the output would be:

    5
    5
    5
    
since variable x is accessible even within the scope of function g

## Problem 6

```
template <typename T>

// Raw Array:
void shuffle(T* inputArray){};

// Standard Library Array:
void shuffle(std::array<T,inputArray.size()>){};   
```
