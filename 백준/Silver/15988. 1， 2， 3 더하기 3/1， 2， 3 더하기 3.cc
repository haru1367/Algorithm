#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long dp[1000001] = { 0 };
int main() {
	int T;
	cin >> T;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 1000001; i++) {
		dp[i] = (dp[i - 1]%1000000009 + dp[i - 2]%1000000009 + dp[i - 3]%1000000009)%1000000009;
	}
	for (int i = 1; i <= T; i++) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
}