#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than key
        // one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

//

code using swap function

#include <iostream>
#include <algorithm>   // for swap()

using namespace std;

void insertionSort(int arr[], int n) {

    for (int i = 1; i < n; i++) {

        int j = i;

        // Swap elements until correct position
        while (j > 0 && arr[j] < arr[j - 1]) {

            swap(arr[j], arr[j - 1]);

            j--;
        }
    }
}




Start with the second element (consider first element as sorted)

Pick the next element (key) from the unsorted portion

Compare the key with elements in the sorted portion:

Shift elements greater than the key one position right

Stop when you find an element ≤ the key

Insert the key in its correct position

Repeat until all elements are processed
