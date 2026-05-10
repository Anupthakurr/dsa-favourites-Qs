#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high) {

    vector<int> temp;

    int left = low;
    int right = mid + 1;

    // Merge two sorted halves
    while(left <= mid && right <= high) {

        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Remaining elements from left half
    while(left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Remaining elements from right half
    while(right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy back to original array
    for(int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int>& arr, int low, int high) {

    // Base case
    if(low >= high)
        return;

    int mid = low + (high - low) / 2;

    // Sort left half
    mergeSort(arr, low, mid);

    // Sort right half
    mergeSort(arr, mid + 1, high);

    // Merge both halves
    merge(arr, low, mid, high);
}

int main() {

    vector<int> arr = {5, 2, 8, 1, 9, 3};

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array:\n";

    for(int x : arr) {
        cout << x << " ";
    }

    return 0;
}
