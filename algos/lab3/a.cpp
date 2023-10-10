#include <algorithm>
#include <iostream>
using namespace std;

int bin_search(int* a, int n, int x) {
  int result = -1;
  int l = 0;
  int r = n - 1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (a[m] == x) {
      result = m;
      break;
    }
    if (a[m] > x) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return result;
}

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i] = x;
  }

  int dlina;
  int shirina;
  int number;
  int chetchik;
  chetchik = 0;
  cin >> dlina;
  cin >> shirina;
  int b[dlina][shirina];
  int singleArr[dlina * shirina];

  for (int i = 0; i < dlina; i++) {
    for (int j = 0; j < shirina; j++) {
      cin >> number;
      b[i][j] = number;
    }
  }
  for (int k = 0; k < dlina; k++) {
    if (k % 2 == 0) {
      for (int i = 0; i < shirina; i++) {
        singleArr[chetchik] = b[k][i];
        chetchik++;
      }
    } else if (k % 2 == 1) {
      for (int i = 0; i < shirina; i++) {
        singleArr[chetchik] = b[k][shirina - i - 1];
        chetchik++;
      }
    }
  }


  reverse(singleArr, singleArr + chetchik);
  int sizeA = sizeof(singleArr) / sizeof(int);

  int indexI;
  int indexJ;
  for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
    indexI = 0;
    indexJ = 0;
    int singleIndex = sizeof(singleArr) / sizeof(int) - 1 -
                      bin_search(singleArr, sizeA, a[i]);

    if (singleIndex == sizeof(singleArr) / sizeof(int)) {
      cout << "-1" << endl;
      continue;
    }

    int ostatok = singleIndex % shirina;
    int del = singleIndex / shirina;
    indexI = del;
    if (del % 2 == 1) {
      indexJ = shirina - 1 - ostatok;
    } else if (del % 2 == 0) {
      indexJ = ostatok;
    }
    cout << indexI << ' ' << indexJ << endl;
  }


  return 0;
}