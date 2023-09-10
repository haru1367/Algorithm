#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int dp[100001];
int main() {
	int n;
	cin >> n;
	vector<int>num;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		num.push_back(k);
	}
	dp[1] = num[0];
	if (n >= 2) {
		for (int i = 2; i <= n; i++) {
			dp[i] = max(dp[i - 1] + num[i - 1], num[i-1]);
		}
	}
	int maxn = -1000;
	for (int i = 1; i <= n; i++) {
		maxn = max(maxn, dp[i]);
	}
	cout << maxn << '\n';

}
