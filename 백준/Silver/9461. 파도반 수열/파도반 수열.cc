#include <iostream>
#include <cmath>
using namespace std;
long long dp[101];
int main() {
	int T;
	cin >> T;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= 100; i++) {
		dp[i] = dp[i - 3] + dp[i - 2];
	}
	for (int i = 1; i <= T; i++) {
		int k;
		cin >> k;
		cout << dp[k] << '\n';
	}
}