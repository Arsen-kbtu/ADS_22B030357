#include <iostream>
using namespace std;
void merge(int arr[], int left[], int lsize, int right[], int rsize) {
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
void mergeSort(int arr[], int size){
   
    if(size<=1){
        return;
    }
    int lsize=size/2, rsize=size-lsize; //2 3
    int left[lsize], right[rsize];
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
    int n,m;
    cin>>n;
    int arr1[n];
    for(int i=0; i<n; i++){
        cin>>arr1[i];
    }
    cin>>m;
    int arr2[m], arr[n+m];
    for(int i=0; i<m; i++){
        cin>>arr2[i];
    }
    merge(arr, arr1, n, arr2, m);
    for(int i=0; i<n+m; i++){
        cout<<arr[i]<<" ";
    }
}