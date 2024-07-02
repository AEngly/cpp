#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

// ABOUT

// 1) How to compile this program?
// g++ -o memory1 memory1.cpp

// 2) What is the purpose of this program?
// This program generates n random numbers and stores them in an array. The array is then printed and the sum of the elements is calculated.

// 3) Using new instead of malloc
// The 'new' operator is used to allocate memory on the heap. It returns a pointer to the first element of the array.
// The pointer is assigned to the variable 'array' which is of type 'int*'. The 'new' operator initializes the memory to zero.
// The keyword 'new' was introduced to overcome deficiencies with malloc. The 'new' operator is a part of the C++ language and is not available in C.

int main() {

    // Seed the random number generator
    int n;  // Number of elements
    std::cout << "\nEnter the number of elements: ";
    std::cin >> n;

    // Seed the random number generator
    srand(time(0));

    // Print that we wish to generate numbers
    std::cout << std::endl << "Generating " << n << " random numbers in the range 0 to " << RAND_MAX << ". Finally, the sum is displayed." << std::endl;
    std::cout << std::endl;

    // Dynamically allocate memory for an array of n integers (the 'new' operator is used to allocate memory on the heap. It returns a pointer to the first element of the array. The pointer is assigned to the variable 'array' which is of type 'int*')
    int* array = new int[n];

    // Check if memory allocation was successful
    if (!array) {
        std::cerr << "Memory allocation failed!" << std::endl;
        return 1;
    }

    // Fill the array with random integers (the 'new' operator initializes the memory to zero)
    for (int i = 0; i < n; ++i) {
        array[i] = rand();
    }

    // Print the elements of the array
    for (int i = 0; i < n; ++i) {
        std::cout << "array[" << i << "] (" << &array[i] << ") = " << array[i] << std::endl;
    }

    // Print space
    std::cout << std::endl;

    // Equivalently, it can be retrieved directly (array + 1 will move pointer 4 bytes ahead of array).
    long int sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cout << "array[" << i << "] (" << array + i << ") = " << *(array + i) << std::endl;
        sum += array[i];
    }

    // Display the sum
    std::cout << std::endl << "Sum of the elements: " << sum << std::endl << std::endl;

    // Deallocate the memory and return 0
    delete[] array;
    return 0;
}