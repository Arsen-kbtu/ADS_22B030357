#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int LPS(string hay, int m, string s) {
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;
    while (i < m) {
        if (s[i] == hay[len]) {
            lps[i] = len + 1;
            len++;
            i++;
        } else if (len != 0) {
            len = lps[len - 1];
        } else {
            i++;
        }
    }
    int res = lps[m - 1];
    return res;
}

int main() {
    string s;
    cin >> s;
    s[0] = tolower(s[0]);

    int n;
    cin >> n;

    int maxLPS = -1;
    vector<string> maxLPSStrings;

    for (int i = 0; i < n; i++) {
        string current;
        cin >> current;

        string modified = current;
        modified[0] = tolower(current[0]);

        int length = LPS(modified, s.size(), s);

        if (length > maxLPS) {
            maxLPS = length;
            maxLPSStrings.clear();
            maxLPSStrings.push_back(current);
        } else if (length == maxLPS) {
            maxLPSStrings.push_back(current);
        }
    }

    if (maxLPS == 0) {
        cout << 0;
    } else {
        cout << maxLPSStrings.size() << endl;
        for (auto cur : maxLPSStrings) {
            cout << cur << endl;
        }
    }

    return 0;
}
