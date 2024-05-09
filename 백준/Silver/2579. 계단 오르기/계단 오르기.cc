#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int dp[301][3] = { 0 };
int stair[301];

int solution(int N) {
	int answer = 0;
	dp[0][1] = 0;
	dp[0][2] = 0;
	dp[1][1] = stair[1];
	dp[1][2] = stair[1];
	for (int i = 2; i <= N; i++) {
		dp[i][1] = max(dp[i - 2][2] + stair[i],dp[i-2][1] + stair[i]);
		dp[i][2] = dp[i - 1][1] + stair[i];
	}
	
	answer = max(dp[N][1], dp[N][2]);
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int numStair = N;
	int index = 1;
	while (N > 0) {
		int k;
		cin >> k;
		stair[index] = k;
		index++;
		N--;
	}
	cout << solution(numStair);
}