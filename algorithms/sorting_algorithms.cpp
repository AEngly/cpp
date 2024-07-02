#include "sorting_algorithms.hpp"
#include <iostream>
#include <algorithm> // Add this line to include the <algorithm> header

// Bubble Sort implementation (in-place)
void bubbleSort(std::vector<int>& nums) {
    int n = nums.size();
    bool swapped;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (nums[j] > nums[j + 1]) {
                std::swap(nums[j], nums[j + 1]);
                swapped = true;
            }
        }
        // If no elements were swapped in inner loop, array is already sorted
        if (!swapped) break;
    }
}

// Function to generate random numbers
std::vector<int> generateRandomNumbers(int size, int MAX_INT) {
    std::vector<int> nums(size);
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < size; ++i) {
        nums[i] = rand() % MAX_INT;  // Generate numbers between 0 and 999
    }
    return nums;
}

// Function to print the elements of a vector (only first 20 elements)
void printVector(const std::vector<int>& nums) {
    int count = 0;
    int max_iter = std::min(nums.size(), static_cast<size_t>(20)); // Add static_cast to ensure correct type conversion
    for (int i = 0; i < max_iter; ++i) {
        std::cout << nums[i] << " ";
        count++;
        if (count >= 20) break;  // Print only the first 20 elements
    }
    std::cout << std::endl;
}