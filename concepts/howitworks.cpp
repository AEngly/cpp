#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <cmath>
#include <thread>  // Add this line to include the <thread> header

// OPERATORS

// Operator: * (dereference operator)
// Operator: & (address-of operator)
// Operator: * (pointer declaration)

void increment(int& num) {
    std::cout << "Memory location of num: " << &num << std::endl;
    num++;  // Modifies the original value of num
}

int main() {

    // Declare integers
    int a;
    int b;

    // Assign to the integers
    a = 10;
    b = a; // Value of a is copied to address of b

    // Regular assignments
    std::cout << std::endl;
    std::cout << "------ REGULAR ASSIGNMENTS ------" << std::endl;
    std::cout << "BEFORE: a = " << a << std::endl;
    std::cout << "BEFORE: b = " << a << std::endl;
    a = a + 1;
    std::cout << "AFTER: a = " << a << std::endl;
    std::cout << "AFTER: b = " << b << std::endl;
    std::cout << std::endl;

    // Declare integers
    int c;
    int& d = c;  // Reference declaration: b is a reference to 'c'

    // Assign to the integers
    c = 10;

    // Regular assignments
    std::cout << "------ USING REFERENCES ------" << std::endl;
    std::cout << "BEFORE: c = " << c << std::endl;
    std::cout << "BEFORE: d = " << d << std::endl;
    c += 1;  // Modify 'c'
    std::cout << "AFTER: c = " << c << std::endl;
    std::cout << "AFTER: d = " << d << std::endl;
    std::cout << std::endl;

    // Direct manipulation of in memory
    std::cout << "------ MODIFY MEMORY LOCATION ------" << std::endl;
    std::cout << "BEFORE: c = " << c << std::endl;
    std::cout << "BEFORE: d = " << d << std::endl;
    increment(c);  // Modify 'c'
    std::cout << "AFTER: c = " << c << std::endl;
    std::cout << "AFTER: d = " << d << std::endl;
    std::cout << &d << std::endl;
    std::cout << std::endl;

    // Create a pointer
    std::cout << "------ CREATE POINTER ------" << std::endl;
    int x = 10;
    int* y = &x;  // Pointer declaration: y is a pointer to 'x'
    std::cout << "Value of x: " << x << std::endl;
    std::cout << "Address of x: " << &x << std::endl;
    std::cout << "Value of y: " << y << std::endl;
    std::cout << "Address of y: " << &y << std::endl;
    std::cout << "Value stored at address: " << *y << std::endl;
    std::cout << std::endl;

}