#include <iostream>
#include <vector>
#include <stdexcept>

class KaryHeap {
public:
    KaryHeap(int k) : k(k) {}

    void insert(int element) {
        heap.push_back(element);
        upHeap(heap.size() - 1);
    }

    int deleteMin() {
        if (heap.empty()) {
            throw std::runtime_error("Heap is empty");
        }
        int minElement = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        downHeap(0);
        return minElement;
    }

    void heapify(const std::vector<int>& array) {
        heap = array;
        for (int i = (heap.size() / k) - 1; i >= 0; --i) {
            downHeap(i);
        }
    }

    void printHeap() const {
        for (int element : heap) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

private:
    std::vector<int> heap;
    int k;

    void upHeap(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / k;
            if (heap[index] >= heap[parentIndex]) {
                break;
            }
            std::swap(heap[index], heap[parentIndex]);
            index = parentIndex;
        }
    }

    void downHeap(int index) {
        while (true) {
            int smallest = index;
            for (int i = 1; i <= k; ++i) {
                int childIndex = k * index + i;
                if (childIndex < heap.size() && heap[childIndex] < heap[smallest]) {
                    smallest = childIndex;
                }
            }
            if (smallest == index) {
                break;
            }
            std::swap(heap[index], heap[smallest]);
            index = smallest;
        }
    }
};
