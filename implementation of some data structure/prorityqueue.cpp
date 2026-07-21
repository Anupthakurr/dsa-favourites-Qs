#include <iostream>
using namespace std;

class PriorityQueue {
    int* arr;
    int size;
    int capacity;

public:
    PriorityQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        size = 0;
    }

    ~PriorityQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return size == 0;
    }

    int top() {
        if (isEmpty()) {
            cout << "Priority Queue is Empty\n";
            return -1;
        }
        return arr[0];
    }

    void push(int value) {
        if (size == capacity) {
            cout << "Priority Queue is Full\n";
            return;
        }

        arr[size] = value;
        int index = size;
        size++;

        // Heapify Up
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Priority Queue is Empty\n";
            return;
        }

        arr[0] = arr[size - 1];
        size--;

        int index = 0;

        // Heapify Down
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && arr[left] > arr[largest])
                largest = left;

            if (right < size && arr[right] > arr[largest])
                largest = right;

            if (largest != index) {
                swap(arr[index], arr[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

    void print() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq(10);

    pq.push(50);
    pq.push(30);
    pq.push(40);
    pq.push(10);
    pq.push(60);

    cout << "Heap: ";
    pq.print();

    cout << "Top: " << pq.top() << endl;

    pq.pop();

    cout << "After Pop: ";
    pq.print();

    cout << "Top: " << pq.top() << endl;

    return 0;
}
