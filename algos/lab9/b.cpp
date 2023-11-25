#include <iostream>
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
int KMPSearch(string txt, string pat){
    int k=0;
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
            // cout<<"Found pattern at index "<< i - j<<endl;
            k++;
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
    return k;
}
int main(){
    string text, pattern;
    int n;
    cin>>pattern>>n>>text;
    int i=KMPSearch(text, pattern);
    if(n>i){
        cout<<"NO";
    }
    else{
        cout<<"YES";
    }
}