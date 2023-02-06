#include <iostream>
using namespace std;

int print(int arr[], int size){

    cout<<"Size of array is "<<size<<endl;

    for (int i = 0; i < size; i++){

        cout << arr[i] << " ";
    }
    cout << endl;
}

bool search(int arr[], int size, int key){

    print(arr,size);
    // base case
    if (size == 0){

        return false;
    }

    if (arr[0] == key){

        return true;
    }
    else{
        bool remainingPart = search(arr + 1, size - 1, key);
        return remainingPart;
    }
}

int main(){

    int arr[6] = {3,6,20,8,9,4};
    int size = 6;
    int key;
    cout << "Enter the Element for the Search ";
    cin >> key;

    bool found = search(arr, size, key);

    if (found){

        cout << "Key is Present " << endl;
    }
    else{

        cout << "Key is Absent " << endl;
    }

    return 0;
}