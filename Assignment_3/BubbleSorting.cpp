#include<bits/stdc++.h>
using namespace std;

int bubbleSort(int arr[],int n){

     for(int i=0;i<n-1;i++){

        for(int j=0;j<n-i-1;j++){
            
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }   
        }
    }
}

int main(){

    int arr[6]={9,4,5,8,1,7};
    int n=6;

    bubbleSort(arr,6);
  
    for(int i=0;i<6;i++){

        cout<<arr[i]<<" ";
    }

    return 0;
}