# Variadic Functions and Format Specifiers
## Variadic Functions
A variadic function is a function that can accept a variable number of arguments. In C, variadic functions are defined using the stdarg.h header, which provides a set of macros for accessing the variable arguments passed to the function.

To define a variadic function, you need to specify an ellipsis (...) after the last fixed parameter in the function’s parameter list. This indicates that the function can accept additional arguments after the fixed parameters. Here’s an example of a simple variadic function that calculates the sum of its arguments:
 ```c
#include <stdarg.h>
#include <stdio.h>

int sum(int count, ...) {
    va_list args;
    va_start(args, count);

    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }

    va_end(args);
    return total;
}

int main() {
    printf("%d\n", sum(3, 1, 2, 3)); // 6
    printf("%d\n", sum(5, 1, 2, 3, 4, 5)); // 15
    return 0;
}
```

In this example, the sum function takes an int parameter named count, which specifies the number of variable arguments passed to the function. The ... after count indicates that the function can accept additional int arguments after count.

Inside the sum function, we use the va_list, va_start, and va_arg macros from the stdarg.h header to access the variable arguments. The va_list macro defines a variable named args that will be used to hold the variable argument list. The va_start macro initializes args with the first variable argument. The va_arg macro is then used inside a loop to retrieve each argument from args, one at a time. Finally, the va_end macro is called to clean up the memory used by args.

## Format Specifiers
Format specifiers are special character sequences used in formatted input/output functions like printf and scanf to specify how arguments should be formatted when printed or read. Each format specifier starts with a '%' character and is followed by one or more characters that specify the type of argument and how it should be formatted.

Here are some common format specifiers and their meanings:

`%d`: Prints an int value as a decimal integer.
`%f`: Prints a float or double value as a floating-point number.
`%c`: Prints a char value as a character.
`%s`: Prints a char * pointer to a string as a sequence of characters.
`%p`: Prints a pointer value as an address in hexadecimal format.
`%x`: Prints an unsigned integer value as a hexadecimal number.
Here’s an example that uses some of these format specifiers to print different types of values:
```c
#include <stdio.h>

int main() {
    int x = 42;
    double y = 3.14;
    char c = 'A';
    char *s = "Hello, world!";

    printf("x = %d\n", x);
    printf("y = %f\n", y);
    printf("c = %c\n", c);
    printf("s = %s\n", s);

    return 0;
}
```
In this example, we use the %d, %f, %c, and %s format specifiers to print the values of the x, y, c, and s variables in different formats.
