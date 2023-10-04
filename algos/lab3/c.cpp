#include <iostream>
using namespace std;

int main(){
    int  n, q;
    cin>>n>>q;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int que[q][4];
    for(int i=0;i<q;i++){
        cin>>que[i][0]>>que[i][1]>>que[i][2]>>que[i][3];
    }
    for(int i=0;i<q;i++){
        int c=0;
        for(int j=0;j<n;j++){
            if((arr[j]>=que[i][0]&&arr[j]<=que[i][1])||(arr[j]>=que[i][2]&&arr[j]<=que[i][3])){
                c++;
            }
        }
        cout<<c<<endl;
    }
}