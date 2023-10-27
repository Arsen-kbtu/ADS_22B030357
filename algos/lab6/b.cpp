#include <iostream>
#include <vector>
using namespace std;
vector<int> bubbleSort(vector<int> v){
    int size=v.size();
    while(size!=0){
        for(int i=0; i<size-1; i++){
            if(v[i]>v[i+1]){
                char temp=v[i];
                v[i]=v[i+1];
                v[i+1]=temp;
            }
        }
        size--;
    }
    return v;
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
    v3=bubbleSort(v3);
    for(int i=0; i<v3.size();i++){
        cout<<v3[i]<<" ";
    }

}