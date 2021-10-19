#include <climits>
#include <iostream>
using namespace std;

int coinChange(int n, int* denominations, int length, int* dp) {
  if (n == 0) {
    return 0;
  }

  if (dp[n] != 0) {
    return dp[n];
  }

  int minimum = INT_MAX;
  for (int i = 0; i < length; ++i) {
    if (n - denominations[i] >= 0) {
      int op = coinChange(n - denominations[i], denominations, length, dp);
      minimum = min(op + 1, minimum);
    }
  }

  dp[n] = minimum;
  return dp[n];
}

int main() {
  int* dp = new int[100]{};
  int denominations[] = {1, 7, 10};
  cout << coinChange(26, denominations, 3, dp);
  delete[] dp;
}
