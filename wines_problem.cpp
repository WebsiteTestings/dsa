#include <climits>
#include <iostream>
using namespace std;

int winesProblemTopDown(int* arr, int si, int ei, int counter, int dp[][100]) {
  if (si > ei) {
    return 0;
  }

  if (dp[si][ei] != 0) {
    return dp[si][ei];
  }
  int op1 = INT_MIN;
  int op2 = INT_MIN;

  op1 = arr[si] * counter +
        (winesProblemTopDown(arr, si + 1, ei, counter + 1, dp));
  op2 = arr[ei] * counter +
        (winesProblemTopDown(arr, si, ei - 1, counter + 1, dp));

  dp[si][ei] = max(op1, op2);
  return dp[si][ei];
}

// int winesProblemBottomUp(int* arr) {}

int main() {
  int arr[] = {2, 3, 5, 1, 4};
  int length = sizeof(arr) / sizeof(arr[0]);
  int dp[100][100]{};
  cout << winesProblemTopDown(arr, 0, length - 1, 1, dp) << '\n';
}
