#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	int dp1[41];
	int dp2[41];
	dp1[0] = 1;
	dp2[0] = 0;
	dp1[1] = 0;
	dp2[1] = 1;
	for (int i = 2; i <= 40; i++) {
		dp1[i] = dp1[i - 2] + dp1[i - 1];
		dp2[i] = dp2[i - 2] + dp2[i - 1];
	}
	while (T--) {
		int k;
		cin >> k;
		cout << dp1[k] << " " << dp2[k] << '\n';
	}
}