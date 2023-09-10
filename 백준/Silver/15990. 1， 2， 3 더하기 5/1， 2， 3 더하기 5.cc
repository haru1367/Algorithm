#include <iostream>
#include <cmath>
using namespace std;
long long dp[100001][4];
int main() {
	int n;
	cin >> n;
	dp[1][1] = 1;
	dp[1][2] = 0;
	dp[1][3] = 0;
	dp[2][1] = 0;
	dp[2][2] = 1;
	dp[2][3] = 0;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;
	for (int i = 4; i <= 100000; i++) {
		dp[i][1] = (dp[i - 1][2]%1000000009 + dp[i - 1][3]%1000000009)%1000000009;
		dp[i][2] = (dp[i - 2][1]%1000000009 + dp[i - 2][3]%1000000009)%1000000009;
		dp[i][3] = (dp[i - 3][1]%1000000009 + dp[i - 3][2]%1000000009)%1000000009;
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		cout << (dp[k][1] + dp[k][2] + dp[k][3]) % 1000000009 << '\n';
	}
}