#include <iostream>
#include <cmath>
using namespace std;
void reverse(long long int arr[], long long int i, long long int n, long long int sum){
    if(i==n){
        return;
    }
    long long int x=arr[i]-sum;
    cout<<char((x/pow(2, i))+97);
    sum=arr[i];
    i++;
    reverse(arr, i, n, sum);
}
int main(){
    long long int n;
    cin>>n;
    long long int arr[n];
    for(long long int i=0; i<n; i++){
        cin>>arr[i];
    }
    reverse(arr, 0, n, 0);
}