#include <iostream>
using namespace std;

class MinHeap {
private:
    int* arr;
    int size;
    int capacity;

public:
    MinHeap(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    ~MinHeap() {
        delete[] arr;
    }

    bool isEmpty() {
        return size == 0;
    }

    int getMin() {
        if (isEmpty()) {
            cout << "Heap is Empty\n";
            return -1;
        }
        return arr[0];
    }

    void insert(int value) {
        if (size == capacity) {
            cout << "Heap Overflow\n";
            return;
        }

        arr[size] = value;
        int index = size;
        size++;

        // Heapify Up
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (arr[parent] > arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void deleteRoot() {
        if (isEmpty()) {
            cout << "Heap is Empty\n";
            return;
        }

        arr[0] = arr[size - 1];
        size--;

        int index = 0;

        // Heapify Down
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size && arr[left] < arr[smallest])
                smallest = left;

            if (right < size && arr[right] < arr[smallest])
                smallest = right;

            if (smallest != index) {
                swap(arr[index], arr[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

    void print() {
        if (isEmpty()) {
            cout << "Heap is Empty\n";
            return;
        }

        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main() {

    MinHeap heap(10);

    heap.insert(50);
    heap.insert(30);
    heap.insert(40);
    heap.insert(10);
    heap.insert(60);
    heap.insert(70);

    cout << "Heap: ";
    heap.print();

    cout << "Minimum Element: " << heap.getMin() << endl;

    heap.deleteRoot();

    cout << "After Deleting Root: ";
    heap.print();

    cout << "Minimum Element: " << heap.getMin() << endl;

    return 0;
}
