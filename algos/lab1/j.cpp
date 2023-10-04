#include <iostream>
#include <deque>
using namespace std;
int main(){
    char c;
    deque<int> d, sum;
    int size=0;
    while(c!='!'){
        cin>>c;
        int n;
        switch (c)
        {
        case '+':           
            cin>>n;
            d.push_front(n);
            break;
        case '-':
            cin>>n;
            d.push_back(n);
            break;
        case '*':
            size++;
            if(d.size()==1){
                int s=d.front()+d.back();
                sum.push_back(s);             
                d.pop_back();
                break;
            }
            else if(d.size()==0){
                sum.push_back(-1);
                break;
            }
            else{
                int s=d.front()+d.back();
                sum.push_back(s);               
                d.pop_back();
                d.pop_front();
                break;
            }
        }
    }
    
    for(int i=0; i<size;i++){
        if(sum.front()==-1){
                cout<<"error"<<endl;
                sum.pop_front();
        
        }
        else{
            cout<<sum.front()<<endl;
            sum.pop_front();
        }
        
    }

}