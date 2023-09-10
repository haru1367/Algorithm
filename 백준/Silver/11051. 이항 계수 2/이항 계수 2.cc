#include <iostream>
using namespace std;
int DP[1001][1001];
int main() {
	int N, K;
	cin >> N >> K;
	DP[0][0] = 1;
	DP[1][0] = 1;
	DP[1][1] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				DP[i][j] = 1;
			}
			else if (j == i) {
				DP[i][j] = 1;
			}
			else {
				DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j])%10007;
			}
		}
	}
	cout << DP[N][K] << '\n';
}