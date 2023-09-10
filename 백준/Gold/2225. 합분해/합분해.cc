#include <iostream>
#include <algorithm>
using namespace std;
long long dp[201][201];
int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= 200; i++) {
		dp[1][i] = i;
		dp[i][1] = 1;
	}
	for (int i = 2; i <= 200; i++) {
		for (int j = 2; j <= 200; j++) {
			dp[i][j] = (dp[i - 1][j]%1000000000 + dp[i][j - 1]%1000000000)%1000000000;
		}
	}
	cout << dp[N][K] << '\n';
	
}