#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int * arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int * arr, int low, int mid, int high) {
    int i, j, k;
    int lengthLeft = mid - low + 1;
    int lengthRight = high - mid;

    int arrLeft[lengthLeft], arrRight[lengthRight];

    for (int a = 0; a < lengthLeft; a++) {
        arrLeft[a] = arr[low + a];
    }
    for (int a = 0; a < lengthRight; a++) {
        arrRight[a] = arr[mid + 1 + a];
    }

   
    i = 0; 
    j = 0; 
    k = low; 

    while (i < lengthLeft && j < lengthRight) {
        if (arrLeft[i] <= arrRight[j]) {
            arr[k] = arrLeft[i];
            i++;
        } else {
            arr[k] = arrRight[j];
            j++;
        }
        k++;
    }

    while (i < lengthLeft) {
        arr[k] = arrLeft[i];
        k++;
        i++;
    }

    while (j < lengthRight) {
        arr[k] = arrRight[j];
        k++;
        j++;
    }
}

void mergeSort(int * arr, int length) {
    for (int i = 1; i <= length - 1; i = 2 * i) {
        for (int j = 0; j < length - 1; j += 2 * i) {
            int mid = min(j + i - 1, length - 1);
            int high = min(j + 2 * i - 1, length - 1);
            merge(arr, j, mid, high);
        }
    }
}

int main() {

    int arr[] = {9, 14, 4, 6, 5, 8, 7};

    int length = sizeof(arr) / sizeof(int);

    cout << "Array, before calling the mergeSort() : ";
    printArray(arr, length);

    mergeSort(arr, length);

    cout << "Array, after calling the mergeSort() : ";
    printArray(arr, length);

    return 0;
}

