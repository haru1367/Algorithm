#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int N;
	cin >> N;
	int DP[1001][10] = { 0 };
	for (int i = 0; i <= 9; i++) {
		DP[1][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				DP[i][j] += (DP[i-1][k])%10007;
			}
			DP[i][j] %= 10007;
		}
	}
	int sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += (DP[N][i])%10007;
	}
	cout << sum % 10007 << '\n';
}