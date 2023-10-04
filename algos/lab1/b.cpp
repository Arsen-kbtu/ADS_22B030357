#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  stack<int> s;
  vector<int> v(n);
  vector<int> v2(n, -1);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    s.push(a);
    v[i] = a;
  }

  reverse(v.begin(), v.end());

  int real_size = s.size();
  for (int i = 0; i < real_size; i++) {
    for (int j = i + 1; j < v.size(); j++) {
      if (s.top() >= v[j]) {
        v2[i] = v[j];
        break;
      }
    }
    s.pop();
  }
  reverse(v2.begin(), v2.end());
  for (int i = 0; i < v2.size(); i++) {
    cout << v2[i] << " ";
  }

  return 0;
}