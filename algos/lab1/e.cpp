#include <iostream>
#include <queue>
using namespace std;
int main(){
    queue<int> boris, nurs;
    for(int i=0; i<5;i++){
        int a;
        cin>>a;
        boris.push(a);
    }
    for(int i=0; i<5;i++){
        int a;
        cin>>a;
        nurs.push(a);
    }
    int x=0;
    while(true){
        int b=boris.front(), n=nurs.front();
        boris.pop();
        nurs.pop();
        if((((b>n)&&(b-n!=9))||(b==0&&n==9))){                        
            boris.push(b);
            boris.push(n);
        }
        else{
            nurs.push(b);
            nurs.push(n);
        }
        x++;
        if(boris.empty()){
            cout<<"Nursik "<<x;
            return 0;
        }
        if(nurs.empty()){
            cout<<"Boris "<<x;
            return 0;
        }
        if(x>=100000){
            cout<<"blin nichya";
            return 0;
        }
    }
}