#include <iostream>
#include <vector>
#include <chrono>
#include <random>

// Algorithm: Bubble Sort
// Explanation: Takes a reference to a vector and returns nothing (modifies it in-place -> original changes)
// Time complexity: Theta(n^2)
// Space complexity: Theta(n)
void bubbleSort(std::vector<int>& arr) {

    // Get the number of elements of the array and cast it to the type int
    int n = (int)arr.size();

    // For each element, check to make sure all previous elements are sorted (n - 1 is fine because on last iteration the 2nd element is in place and hence element 1 is the smallest)
    for (int i = 0; i < n - 1; ++i) {

        // Set flag to indicate that no swaps have occured so far
        bool swapped = false;

        // "Bubble up" larger elements by comparing and swapping adjacent pairs (here -1 make sure we can index [j + 1])
        for (int j = 0; j < (n - i) - 1; ++j) {
            if (arr[j] > arr[j + 1]) {

                //Alternative: std::swap(arr[j], arr[j + 1]);
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                // Set flag to indicate that swap occured
                swapped = true;
            }
        }

        // If no swaps occurred, then the array is fully sorted
        if (!swapped) break;
    }
}

int main() {

    // Allocate memory for a vector of 5000 integers
    const int N = 100000;
    std::vector<int> data(N);

    // Generate random data
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, N * 10);
    for (int& x : data) x = dist(rng);

    // Copy data for sorting to keep original intact (not strictly needed here)
    std::vector<int> dataCopyBubbleSort = data;

    std::cout << "\n\nSorting with Bubble Sort: " << N << " elements\n";

    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort(dataCopyBubbleSort);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> diff = end - start;

    std::cout << "Total computation time: " << diff.count() << " seconds\n";

    // Optional: print first 10 sorted elements to confirm correctness
    std::cout << "First 10 sorted elements from Bubble Sort: ";
    for (int i = 0; i < 10 && i < (int)dataCopyBubbleSort.size(); ++i) {
        std::cout << dataCopyBubbleSort[i] << " ";
    }
    std::cout << "\n\n";

    return 0;
}