#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <cmath>
#include <thread>  // Add this line to include the <thread> header

int main() {

    // Seed the random number generator
    srand(time(0));

    // Loop to allocate memory in a way that demonstrates a memory leak
    while (true) {

        try {

            // Generate a random size for the array
            int size = rand() % 100000000 + 1;

            // Dynamically allocate memory for an array of integers
            int* array = new int[size];

            // Calculate the size of allocated memory in kilobytes
            long long int sizeInKB = size * sizeof(int) / std::pow(2, 20);

            // Print a message showing the allocated size in kilobytes
            std::cout << "Allocated " << sizeInKB << " MB memory for an array of integers." << std::endl;

            // Sleep for 0.5 seconds
            // std::this_thread::sleep_for(std::chrono::milliseconds(50));

            // Note: We intentionally omit deleting 'array' to simulate a memory leak

            // Uncomment to avoid the memory leak
            // delete[] array;
            // std::cout << "Removed the previously " << sizeInKB << " MB allocated memory." << std::endl;

        } catch (std::bad_alloc& ba) {
            std::cerr << "\nException caught: " << ba.what() << std::endl;
            std::cerr << "This is thrown whenever 'new' fails to allocate memory dynamically due to insufficient memory availability.\n" << std::endl;
            return 1;
        }
    }

    return 0;
}