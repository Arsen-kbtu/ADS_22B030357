#include <iostream>
#include <algorithm>

using namespace std;
int main(){
    int arr[2, 3, 1, 7, 11, 6, 7];
    sort(arr[0], arr[6]);
    int r=6, l=0, m, x;
    cin>>x;
    while(l<r){
        m=l+((r-l)/2);
        if(x>arr[m]){
            l=m+1;
        }
        else{
            r=m;
        }
    }
    
    
    
    
    return 0;
}