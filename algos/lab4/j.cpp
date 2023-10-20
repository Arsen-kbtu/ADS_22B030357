#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
void binary(int n,int arr[]){
    if(n==0){
        return;
    }
    int m, l=0, r=n-1;
    m=l+((r-l)/2);
    cout<<arr[m]<<" ";
    int left[r/2], right[r/2];
    for(int i=0;i<m;i++){
        left[i]=arr[i];
        right[i]=arr[i+m+1];
    }
    binary(r/2, left);
    binary(r/2, right);
    return;
}
int main(){
    int n;
    cin>>n;
    int size=pow(2, n)-1;
    int arr[size];
    for(int i=0; i<size;i++){
        cin>>arr[i];
    }
    sort(arr, arr+size);
    binary(size, arr);
}