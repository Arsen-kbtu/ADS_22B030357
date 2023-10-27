#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, string> nick;
    for (int i = 0; i < n; i++) {
        string s1;
        cin >> s1;
        string s2;
        cin >> s2;
        bool found = false;
        for (map<string, string>::iterator it = nick.begin(); it != nick.end(); it++) {
            if (it->second == s1) {
                nick[it->first] = s2;
                found = true;
                break;
            }
        }
        if (!found)
            nick[s1] = s2;
    }
    cout << nick.size() << "\n";
    for (map<string, string>::iterator it = nick.begin(); it != nick.end(); it++) {
        cout << it->first << " " << it->second << "\n";
    }
}