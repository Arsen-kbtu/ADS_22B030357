#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int n;
    cin>> n;
    int c;
    
    vector<int> arr[n];
    for (int i = 0; i < n; i++){
        for(int j=0; j<n; j++){
            cin>>c;
            arr[i].push_back(c);
        }
    }    
    int start, finish;
    cin>>start>>finish;
    start--, finish--;
    bool visited[100000];
    int dst[100000];
    for(int i=0; i<100000;i++){
        dst[i]=-1;
    }
    queue<int> q;
    q.push(start);
    visited[start]=true;
    dst[start]=0;
    while(q.size()!=0){
        int cur= q.front();
        q.pop();
        // cout<<cur+1<<" ";
        for(int i=0; i<n;i++){
            if(arr[cur][i]==1&&!visited[i]){
                q.push(i);
                visited[i]=true;
                dst[i]=dst[cur]+1;
            }
        }
        
    }
    cout<<dst[finish];
}
