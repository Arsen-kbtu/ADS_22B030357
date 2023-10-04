#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    int T;
    cin>>T;
    int arr[T];
    for (int i = 0; i < T; i++){
        cin>>arr[i];
    }
    queue<int> q[T];
    for (int i = 0; i < T; i++){
        int a=arr[i];
        while(a>0){
            q[i].push(a);
            for (int j = 0; j < a; j++){
                int b=q[i].front();
                q[i].pop();
                q[i].push(b);
            }
            a--;           
        }
        string s;
        while (!q[i].empty()){
            int c=q[i].front();
            string d= to_string(c);
            s+=" ";
            reverse(d.begin(), d.end());
            s+=d;
            q[i].pop();   
        }
        reverse(s.begin(), s.end());
        cout<<s<<endl;

    }

}