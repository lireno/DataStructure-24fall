#include "HeapSort.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

template <typename T>
bool check(std::vector<T>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

enum ArrayType { RANDOM,
                 ORDERED,
                 REVERSE,
                 REPETITIVE };

std::vector<int> generateArray(int size, ArrayType type) {
    std::vector<int> arr(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 10000);

    switch (type) {
    case RANDOM:
        for (int i = 0; i < size; i++) {
            arr[i] = dis(gen);
        }
        break;

    case ORDERED:
        for (int i = 0; i < size; i++) {
            arr[i] = static_cast<int>(i);
        }
        break;

    case REVERSE:
        for (int i = 0; i < size; i++) {
            arr[i] = static_cast<int>(size - i);
        }
        break;

    case REPETITIVE:
        int r = size / 4;
        for (int i = 0; i < size; i++) {
            arr[i] = dis(gen) % r;
        }
        break;
    }

    return arr;
}

int main() {
    const size_t SIZE = 1000000; // Array size
    const std::vector<ArrayType> TEST_TYPES = {RANDOM, ORDERED, REVERSE, REPETITIVE};

    for (const auto& type : TEST_TYPES) {
        // Generate array
        std::vector<int> arr = generateArray(SIZE, type);
        std::vector<int> arr_2 = arr;

        // Test custom HeapSort
        auto start = std::chrono::high_resolution_clock::now();
        HeapSort::sort(arr);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        // Check correctness
        if (check(arr)) {
            std::cout << "HeapSort passed for type " << type << " in " << elapsed.count() << " seconds." << std::endl;
        } else {
            std::cout << "HeapSort failed for type " << type << "." << std::endl;
        }

        // Test std::sort_heap
        start = std::chrono::high_resolution_clock::now();
        std::make_heap(arr_2.begin(), arr_2.end());
        std::sort_heap(arr_2.begin(), arr_2.end());
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;

        // Check correctness
        if (check(arr_2)) {
            std::cout << "std::sort_heap passed for type " << type << " in " << elapsed.count() << " seconds." << std::endl;
        } else {
            std::cout << "std::sort_heap failed for type " << type << "." << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}