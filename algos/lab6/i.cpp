#include <iostream>
using namespace std;
string insertionSort(string s, int size){
    for(int i=1;i<size;i++){
        for(int j=i;j>0;j--){
            if(s[j]-'0'<s[j-1]-'0'){
                char temp=s[j];
                s[j]=s[j-1];
                s[j-1]=temp;
            }
        }
    }
    return s;
}
int main(){
    string s;
    cin>>s;
    s=insertionSort(s, s.size());
    cout<<s;
}