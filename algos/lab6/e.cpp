#include <iostream>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m;j++){
            cin>>arr[i][j];
        }
    }
    for(int j=0; j<m;j++){
        int size=n;
        while(size!=0){
        for(int i=0; i<size-1; i++){
            if(arr[i][j]<arr[i+1][j]){
                int temp=arr[i][j];
                arr[i][j]=arr[i+1][j];
                arr[i+1][j]=temp;
            }
        }
        size--;
    }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}