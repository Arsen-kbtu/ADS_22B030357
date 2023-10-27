#include <iostream>
using namespace std;
void bubbleSort(string arr[], int size){
    while(size!=0){
        for(int i=0; i<size-1; i++){
            string date1=arr[i], date2=arr[i+1];
            int day1=(date1[0]-'0')*10+date1[1]-'0', month1=(date1[3]-'0')*10+date1[4]-'0', year1=(date1[6]-'0')*1000+(date1[7]-'0')*100+(date1[8]-'0')*10+date1[9]-'0';
            int day2=(date2[0]-'0')*10+date2[1]-'0', month2=(date2[3]-'0')*10+date2[4]-'0', year2=(date2[6]-'0')*1000+(date2[7]-'0')*100+(date2[8]-'0')*10+date2[9]-'0';
            if(year1>year2){
                string temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
            if(year1==year2){
                if(month1>month2){
                    string temp=arr[i];
                    arr[i]=arr[i+1];
                    arr[i+1]=temp;
                }
                if(month1==month2){
                    if(day1>day2){
                        string temp=arr[i];
                        arr[i]=arr[i+1];
                        arr[i+1]=temp;
                    }
                }
            }
        }
        size--;
    }
    return;
}
int main(){
    int n;
    cin>>n;
    string arr[n];
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<endl;
    }
    
}