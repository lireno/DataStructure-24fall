#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <algorithm>
#include <iostream>
#include <vector>

#include <functional>
#include <vector>

namespace HeapSort {

template <typename Comparable, typename Comparator = std::less<Comparable>>
// Recursively heapify the i-th element
void heapify(std::vector<Comparable>& arr, int n, int i, Comparator comp = Comparator()) {
    int largest = i;   // Assume the largest element is current node
    int l = 2 * i + 1; // left child
    int r = 2 * i + 2; // right child

    if (l < n && comp(arr[largest], arr[l])) {
        largest = l;
    }

    if (r < n && comp(arr[largest], arr[r])) {
        largest = r;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest, comp);
    }
}

template <typename Comparable, typename Comparator = std::less<Comparable>>
void buildHeap(std::vector<Comparable>& arr, Comparator comp = Comparator()) {
    int n = arr.size();

    // Start heapifying from the last non-leaf node
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, comp);
    }
}

template <typename Comparable, typename Comparator = std::less<Comparable>>
void sort(std::vector<Comparable>& arr, Comparator comp = Comparator()) {
    int n = arr.size();

    // Build heap
    buildHeap(arr, comp);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]); // Move root to the end
        heapify(arr, i, 0, comp);  // Heapify the reduced heap
    }
}

} // namespace HeapSort

#endif // HEAPSORT_H