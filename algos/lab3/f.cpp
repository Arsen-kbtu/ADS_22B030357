#include <iostream>
using namespace std;

int main(){
    int  n, p;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cin>>p;
    int power[p];
    for(int i=0;i<p;i++){
        cin>>power[i];
    }
    for(int i=0;i<p;i++){
        int c=0;
        int sum=0;
        for(int j=0;j<n;j++){
            if(power[i]>=arr[j]){
                c++;
                sum+=arr[j];
            }
        }
        cout<<c<<" "<<sum<<endl;
    }
}