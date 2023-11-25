#include <iostream>
#include <vector>
using namespace std;
void computeLPSArray(string pat, int M, int lps[]){
    int len = 0;
    lps[0] = 0; 
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return;
}
void KMPSearch(string txt, string pat){
    int k=0;
    vector<int> v;
    int M = pat.length();
    int N = txt.size();
    int lps[M];
    computeLPSArray(pat, M, lps);
    int i = 0; 
    int j = 0; 
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            k++;
            v.push_back(i-j+1);
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0){
                j = lps[j - 1];
            }
            else{
                i = i + 1;
            }
        }
    }
    cout<<k<<endl;
    for(int c : v){
        cout<<c<<" ";
    }
}
int main(){
    string text, pattern;
    cin>>text>>pattern;
    KMPSearch(text, pattern);
    
}