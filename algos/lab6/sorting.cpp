#include <iostream>
#include <array>
using namespace std;
void bubbleSort(int arr[], int size){
    while(size!=0){
        for(int i=0; i<size-1; i++){
            if(arr[i]>arr[i+1]){
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
        size--;
    }
    return;
}
void insertionSort(int arr[], int size){
    for(int i=1;i<size;i++){
        for(int j=i;j>0;j--){
            if(arr[j]<arr[j-1]){
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
    return;
}
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
void quickSort(int arr[], int size){
    int mid=arr[size-1];
    int left[size], right[size];
}
int main(){
    int arr[5]={6, 2, 7, 3, 1};
    mergeSort(arr, 5);
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<" "<<arr[4]<<" ";
}