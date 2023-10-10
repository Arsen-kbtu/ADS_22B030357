#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
bool isPossible(long long int* a, long long int mid, long long int flight,
                long long int n) {
  long long int usedFlight = 0;
  for (int i = 0; i < n; ++i) {
    long long int num = a[i];
    usedFlight += (num + mid - 1) /
                  mid;  // Calculate how many steps it takes to reach zero
  }
  return usedFlight <= flight;
}

long long int bin_search(long long int* a, long long int n,
                         long long int flight) {
  long long int l = 1;
  long long int r = *max_element(a, a + n);
  long long int cnt = 0;
  while (l < r) {
    long long int m = l + (r - l) / 2;
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
  long long int n, flight;
  cin >> n;
  long long int a[n];
  cin >> flight;
  for (long long int i = 0; i < n; i++) {
    long long int numba;
    cin >> numba;
    a[i] = numba;
  }
  sort(a, a + n);
  cout << bin_search(a, n, flight);
  return 0;
}
// 4 8
// 3 6 7 11

// 5 7
// 10 34 14 6 20