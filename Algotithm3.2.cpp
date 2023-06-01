#include <iostream>
#include <vector>
using namespace std;
class BinaryHeap {
private:
    vector<int> heap;
    void heapify(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }
public:
    BinaryHeap() {}
    BinaryHeap(vector<int> arr) {
        heap = arr;
        for (int i = heap.size() / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }
    int findMax() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }
        return heap[0];
    }
    void deleteMax() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
    }
    void insert(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;
        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    void merge(BinaryHeap& other) {
        for (int i = 0; i < other.heap.size(); i++) {
            insert(other.heap[i]);
        }
        other.heap.clear();
    }
};
int main() {
    BinaryHeap();
    return 0;
}