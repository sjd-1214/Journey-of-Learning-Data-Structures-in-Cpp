#include <iostream>
#include <stdexcept>
#include <algorithm>

class MinMaxHeap {
private:
    int* heap;
    int capacity;
    int length;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }
    int level(int i) { return (i + 1) ? __builtin_clz(i + 1) : 0; }

    void bubbleUp(int i);
    void bubbleDown(int i);
    void swap(int& a, int& b) { int temp = a; a = b; b = temp; }
    void resize(int new_capacity);

public:
    MinMaxHeap(int initial_capacity = 10);
    ~MinMaxHeap();

    bool isEmpty() const { return length == 0; }
    int size() const { return length; }
    int getMin() const;
    int getMax() const;
    void insert(int value);
    void deleteMin();
    void deleteMax();
};

MinMaxHeap::MinMaxHeap(int initial_capacity) : capacity(initial_capacity), length(0) {
    heap = new int[capacity];
}

MinMaxHeap::~MinMaxHeap() {
    delete[] heap;
}

void MinMaxHeap::resize(int new_capacity) {
    int* new_heap = new int[new_capacity];
    for (int i = 0; i < length; ++i) {
        new_heap[i] = heap[i];
    }
    delete[] heap;
    heap = new_heap;
    capacity = new_capacity;
}

void MinMaxHeap::bubbleUp(int i) {
    if (i == 0) return;

    int p = parent(i);
    if (level(i) % 2 == 0) { // Min level
        if (heap[i] > heap[p]) {
            swap(heap[i], heap[p]);
            bubbleUp(p);
        } else {
            int gp = parent(p);
            if (gp >= 0 && heap[i] < heap[gp]) {
                swap(heap[i], heap[gp]);
                bubbleUp(gp);
            }
        }
    } else { // Max level
        if (heap[i] < heap[p]) {
            swap(heap[i], heap[p]);
            bubbleUp(p);
        } else {
            int gp = parent(p);
            if (gp >= 0 && heap[i] > heap[gp]) {
                swap(heap[i], heap[gp]);
                bubbleUp(gp);
            }
        }
    }
}

void MinMaxHeap::bubbleDown(int i) {
    int l = leftChild(i);
    int r = rightChild(i);

    if (l >= size()) return;

    int m = l;
    if (r < size() && heap[r] < heap[l]) m = r;

    if (level(i) % 2 == 0) { // Min level
        if (heap[i] > heap[m]) {
            swap(heap[i], heap[m]);
            bubbleDown(m);
        }
    } else { // Max level
        if (heap[i] < heap[m]) {
            swap(heap[i], heap[m]);
            bubbleDown(m);
        }
    }
}

int MinMaxHeap::getMin() const {
    if (isEmpty()) throw std::out_of_range("Heap is empty");
    return heap[0];
}

int MinMaxHeap::getMax() const {
    if (isEmpty()) throw std::out_of_range("Heap is empty");
    if (size() == 1) return heap[0];
    if (size() == 2) return heap[1];
    return std::max(heap[1], heap[2]);
}

void MinMaxHeap::insert(int value) {
    if (length == capacity) {
        resize(capacity * 2);
    }
    heap[length++] = value;
    bubbleUp(length - 1);
}

void MinMaxHeap::deleteMin() {
    if (isEmpty()) throw std::out_of_range("Heap is empty");
    heap[0] = heap[--length];
    bubbleDown(0);
}

void MinMaxHeap::deleteMax() {
    if (isEmpty()) throw std::out_of_range("Heap is empty");
    if (length == 1) {
        --length;
        return;
    }
    int maxIndex = (length == 2 || heap[1] > heap[2]) ? 1 : 2;
    heap[maxIndex] = heap[--length];
    bubbleDown(maxIndex);
}

int main() {
    MinMaxHeap mmHeap;
    mmHeap.insert(10);
    mmHeap.insert(5);
    mmHeap.insert(20);
    mmHeap.insert(15);

    std::cout << "Min: " << mmHeap.getMin() << std::endl;
    std::cout << "Max: " << mmHeap.getMax() << std::endl;

    mmHeap.deleteMin();
    std::cout << "Min after deletion: " << mmHeap.getMin() << std::endl;
    mmHeap.deleteMax();
    std::cout << "Max after deletion: " << mmHeap.getMax() << std::endl;

    return 0;
}