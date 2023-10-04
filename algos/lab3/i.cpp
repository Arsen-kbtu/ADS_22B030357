#include <iostream>
using namespace std;
int main(){
    int n, x;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cin>>x;
    int l=0, r=n-1, m, f=-1;
    if(x<arr[l]||x>arr[r]){
        
        }
    else{while(l<=r){
        
        m=l+((r-l)/2);
        if(x==arr[m]){
            f=m;
            break;
        }
        else if(x>arr[m]){
            l=m+1;
        }
        else{
            r=m;
        }
    }}
    if(f==-1){
        cout<<"No";
    }
    else{
        cout<<"Yes";
    }
}