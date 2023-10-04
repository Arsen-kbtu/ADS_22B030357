#include <iostream>
using namespace std;

int main(){
    int x, n, m;
    cin>>x;
    int tofind[n];
    for(int i=0; i<x; i++){
        cin>>tofind[i];
    }
    cin>>n>>m;
    int snake[n][m];
    for(int i=0; i<n;i++){
        for(int j; j<m; j++){
            cin>>snake[i][j];
        }
    }
    for(int i=0; i<x; i++){
        int a=tofind[i];
        int up=0, down=n-1, left=0, right=m-1;
        int midi;

    }
}