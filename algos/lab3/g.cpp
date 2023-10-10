#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
bool isPossible(int* a, int mid, int flight, int n) {
  int usedFlight = 0;
  for (int i = 0; i < n; ++i) {
    int num = a[i];
    while (num > 0) {
      num = num - mid;
      usedFlight++;
      //   cout << mid << "MID WAS FLIGHT = " << usedFlight << endl;
    }
  }
  return usedFlight <= flight;
}
int bin_search(int* a, int n, int flight) {
  int l = 1;
  int r = *max_element(a, a + n);
  int cnt = 0;
  while (l < r) {
    int m = l + (r - l) / 2;
    if (isPossible(a, m, flight, n)) {
      r = m;
      //   cout << "sdfsdfsf" << r;
    } else {
      l = m + 1;
    }
  }

  return l;
}

int main() {
  int n, flight;
  cin >> n;
  int a[n];
  cin >> flight;
  for (int i = 0; i < n; i++) {
    int numba;
    cin >> numba;
    a[i] = numba;
  }
  sort(a, a + n);
  cout << bin_search(a, n, flight);
  return 0;
}
// 3 6
// 10 10 10

// 5 7
// 10 34 14 6 20