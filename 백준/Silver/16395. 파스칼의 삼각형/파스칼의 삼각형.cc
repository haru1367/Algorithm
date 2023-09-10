#include <iostream>
#include <cmath>
using namespace std;
int dp[31][31];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= 30; i++) {
		dp[i][1] = 1;
		dp[i][i] = 1;
	}
	for (int i = 2; i <= 30; i++) {
		for (int j = 2; j < i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	cout << dp[n][k] << '\n';

}