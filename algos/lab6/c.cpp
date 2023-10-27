#include <iostream>
#include <climits>
using namespace std;
void merge(long long int arr[], long long int left[], int lsize, long long int right[], int rsize) {
    int i = 0, j = 0, k = 0;
    
    while (i < lsize && j < rsize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < lsize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < rsize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}
void mergeSort(long long int arr[], int size){
   
    if(size<=1){
        return;
    }
    int lsize=size/2, rsize=size-lsize; //2 3
    long long int left[lsize], right[rsize];
    for(int i=0; i<size; i++){
        if(i<lsize){
            left[i]=arr[i];
        }
        else{
            right[i-lsize]=arr[i];
        }
    }
    mergeSort(left, lsize);
    mergeSort(right, rsize);
    merge(arr, left, lsize, right, rsize);
    return;

    
}

int main(){
    int n, diff=INT_MAX;
    cin>>n;
    long long int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr, n);
    for(int i=1;i<n;i++){
        if(arr[i]-arr[i-1]<diff){
            diff=arr[i]-arr[i-1];
        }
    }
    for(int i=1;i<n;i++){
        if(arr[i]-arr[i-1]==diff){
            cout<<arr[i-1]<<" "<<arr[i]<<" ";
        }
    }
}