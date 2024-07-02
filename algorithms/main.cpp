#include <iostream>
#include <vector>
#include <chrono>  // for timing
#include "sorting_algorithms.hpp"

using namespace std;
using namespace std::chrono;

int main() {

    // Specify maximum value for random numbers
    int max_int = 100000; // Maximum value for random numbers
    int max_problem_size = 80000; // Maximum problem size

    // Start by printing empty line
    cout << endl;
    cout << "Demontration of 'bubble sort' algorithm: " << endl;

    // Iterate over problem sizes from 1 to 40000
    for (int size = 1; size <= max_problem_size; size *= 2) { // size doubles each iteration

        // Generate random problem
        vector<int> nums = generateRandomNumbers(size, max_int);

        // Print unsorted array (first 20 elements)
        // cout << "Unsorted array (first 20) for size " << size << ": ";
        // printVector(nums);

        // Timing the sorting process
        auto start = high_resolution_clock::now();
        bubbleSort(nums);
        auto stop = high_resolution_clock::now();

        // Calculate the time taken
        auto duration = duration_cast<microseconds>(stop - start);

        // Print sorted array (first 20 elements)
        // cout << "Sorted using bubbleSort (first 20) for size " << size << ": ";
        // printVector(nums);

        // Print size of problem and timing information
        cout << "(size of problem, duration in seconds): " << "(" << size << ", " << duration.count() / 1e6 << ")" << endl;

    }

    cout << endl;

    return 0;
}