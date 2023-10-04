#include <iostream>
#include <stack>
using namespace std;

int main(){
    string s, s1;
    cin>>s>>s1;
    stack<char> v, v1;
    for (int i = 0; i < s.size(); i++){
        if(s[i]!='#'){
            v.push(s[i]);
        }
        else{
            v.pop();
        }
    }
    for (int i = 0; i < s1.size(); i++){
        if(s1[i]!='#'){
            v1.push(s1[i]);
        }
        else{
            v1.pop();
        }

    }
    if(v1==v){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}