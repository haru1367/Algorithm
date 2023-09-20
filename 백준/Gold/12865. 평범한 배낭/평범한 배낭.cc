#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int dp[101][100001] = { 0 };
int W[101];
int V[101];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int N, K; // N : 물건의 개수,  K : 최대 들 수 있는 무게
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> W[i] >> V[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j - W[i] >= 0) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
				// dp[i][j] : 물건을 i개 사용해 들 수 있는 무게의 합이 j인 경우
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[N][K];
}