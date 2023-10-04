#include <iostream>
#include <queue>
using namespace std;
int main(){
    string s;
    cin>>s;
    queue<char> q, q1;
    for(int i=0; i<s.size(); i++){
        q.push(s[i]);
    }
    q1=q;
    while(!q.empty()){
        
        char c=q.front();
        q.pop();
        if(q.front()==c){
            q.pop();
            c='-';
            q1=q;
            continue;
        }
        else{
            q.push(c);
        }
        if(q1==q){
            cout<<"NO";
            return 0;
        }
        
    }
    cout<<"YES";
}