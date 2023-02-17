#include<bits/stdc++.h>
using namespace std;

void print(int arr[],int s,int e){
  //  cout<<"Size of array is "<<size<<endl;

    for(int i=s;i<=e;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool  binarysearch(int *arr, int s, int e, int key){
    print(arr,s,e);

    // base case

    //element not found
    if(s>e){
        return false;
    }

    int mid=s+(e-s)/2;
    cout<<"Value of arr mid is "<<arr[mid]<<endl;

    // element found
    if(arr[mid]==key){
        return true;
    }
  
    if(arr[mid]<key){
        binarysearch(arr,mid+1,e,key);
    }
    else{
        binarysearch(arr,s,mid-1,key);
    }
}

int main(){

    int arr[8]={1,2,3,4,5,6,7,8};
    int key=8;
    int size=8;

    cout<<"Present or Not "<<binarysearch(arr,0,7,key)<<endl;

    return 0;
}