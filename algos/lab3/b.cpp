#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool isPossible(vector<long long int>& nums, long long int maxSum,
                long long int numBlocks) {
  long long int currentSum = 0;
  long long int blocksUsed = 0;

  for (int i = 0; i < nums.size(); ++i) {
    long long int num = nums[i];
    currentSum += num;
    if (currentSum > maxSum) {
      currentSum = num;
      blocksUsed++;
    }
  }

  return blocksUsed < numBlocks;
}

long long int splitArray(vector<long long int>& nums, long long int numBlocks) {
  long long int left = *max_element(nums.begin(), nums.end());
  long long int right = 0;
  for (long long int i = 0; i < nums.size(); ++i) {
    right += nums[i];
  }

  while (left < right) {
    long long int mid = left + (right - left) / 2;
    if (isPossible(nums, mid, numBlocks)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return left;
}

int main() {
  vector<long long int> nums;
  long long int n;
  cin >> n;
  long long int numBlocks;
  cin >> numBlocks;
  for (long long int i = 0; i < n; i++) {
    long long int numba;
    cin >> numba;
    nums.push_back(numba);
  }

  long long int result = splitArray(nums, numBlocks);
  cout << result << endl;

  return 0;
}