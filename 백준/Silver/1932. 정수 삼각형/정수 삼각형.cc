#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int arr[501][501];
int dp[501][501];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= i; k++) {
			int x;
			cin >> x;
			arr[i][k] = x;
		}
	}
	dp[1][1] = arr[1][1];
	dp[2][1] = dp[1][1] + arr[2][1];
	dp[2][2] = dp[1][1] + arr[2][2];
	if (n >= 3) {
		for (int i = 3; i <= n; i++) {
			dp[i][1] = dp[i - 1][1] + arr[i][1];
			dp[i][i] = dp[i - 1][i - 1] + arr[i][i];
		}
		for (int i = 3; i <= n; i++) {
			for (int j = 2; j < n; j++) {
				dp[i][j] = max(dp[i - 1][j - 1] + arr[i][j], dp[i - 1][j] + arr[i][j]);
			}
		}
	}
	int maxn = 0;
	for (int i = 1; i <= n; i++) {
		maxn = max(maxn, dp[n][i]);
	}
	cout << maxn << '\n';
}