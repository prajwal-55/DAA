#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b){

    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int l, int h){

    int pivot = arr[h]; 
    int i = (l - 1);

    for (int k = l; k <= h - 1; k++){
        if (arr[k] < pivot){
            i++; 
            swap(&arr[i], &arr[k]);
        }
    }
    swap(&arr[i + 1], &arr[h]);

return (i + 1);
}

void quickSort(int arr[], int l, int h){

    if (l < h){
        int pi = partition(arr, l, h);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, h);
    }
}

void print_array(int arr[], int size){

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main(){

    int arr[] = {11, 13, 16, 1, 3, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    print_array(arr, n);

return 0;

}