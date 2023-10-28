#include <iostream>
#include <vector>
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
    cin>>n>>m;
    vector<int> v1, v2, v3;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v1.push_back(a);
    }
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        v2.push_back(a);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<v2.size();j++){
            if(v1[i]==v2[j]){
                v3.push_back(v1[i]);
                v2.erase(v2.begin()+j);
                break;
            }
        }
    }
    int size=v3.size();
    int arr[size];
    for(int i=0; i<size; i++){
        arr[i]=v3[i];
    }
    mergeSort(arr, size);
    for(int i=0; i<v3.size();i++){
        cout<<arr[i]<<" ";
    }

}