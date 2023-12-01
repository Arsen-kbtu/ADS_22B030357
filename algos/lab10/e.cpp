#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int n, q;
    cin>> n>>q;
    int ci;
    
    vector<int> adj[n];
    for (int i = 0; i < n; i++){
        for(int j=0; j<n; j++){
            cin>>ci;
            adj[i].push_back(ci);
        }
    }
    int a, b, c;
    while(q--){
        cin>>a>>b>>c;
        if (adj[a - 1][b - 1] == 1 && adj[a - 1][c - 1] && adj[b - 1][c - 1])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

}