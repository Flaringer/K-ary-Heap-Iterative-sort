#include "kary_heap.cpp"
#include <iostream>
#include <vector>

void iterativeHeapSort(std::vector<int>& array, int k) {
    KaryHeap heap(k);
    heap.heapify(array);

    for (int i = 0; i < array.size(); ++i) {
        array[i] = heap.deleteMin();
    }
}

int main() {
    std::vector<int> array = {10, 3, 15, 7, 8, 23, 74, 18};
    int k = 3;  // Example k-ary heap with k = 3

    std::cout << "Original array: ";
    for (int el : array) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    iterativeHeapSort(array, k);

    std::cout << "Sorted array: ";
    for (int el : array) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    return 0;
}
