#include <iostream>
#include <vector>
using namespace std;
vector<char> bubbleSort(vector<char> v){
    int size=v.size();
    while(size!=0){
        for(int i=0; i<size-1; i++){
            if(v[i]>v[i+1]){
                char temp=v[i];
                v[i]=v[i+1];
                v[i+1]=temp;
            }
        }
        size--;
    }
    return v;
}
int main(){
    int n;
    cin>>n;
    char arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<char> vowels, consonant;
    for(int i=0;i<n;i++){
        if(arr[i]=='a'||arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u'){
            vowels.push_back(arr[i]);
        }
        else{
            consonant.push_back(arr[i]);
        }

    }
    vowels=bubbleSort(vowels);
    consonant=bubbleSort(consonant);
    for(int i=0; i<vowels.size(); i++){
        cout<<vowels[i];
    }
    for(int i=0; i<consonant.size(); i++){
        cout<<consonant[i];
    }
}