#include <iostream>

using namespace std;

char map[100001][3];  // 메모리를 줄이기 위해 char 배열로 설정
int dp[100001][3];	 // 각 경로의 합을 저장하기 위한 dp배열

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;				// 입력받는 줄의 개수
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		dp[1][i] = map[1][i] - '0';
	}    // 첫번째 줄 dp값 저장

	int left, right;
	for (int i = 2; i <= N; i++) {			//max_dp 값 구하기
		left = max(dp[i - 1][0], dp[i - 1][1]); //왼쪽 2개 값 비교
		right = max(dp[i - 1][1], dp[i - 1][2]); // 오른쪽 2개 값 비교

		dp[i][0] = left + map[i][0] - '0';			
		dp[i][1] = max(left, right) + map[i][1] - '0';
		dp[i][2] = right + map[i][2] - '0';
	}
	cout << max(max(dp[N][0], dp[N][1]), dp[N][2]) << " ";

	for (int i = 2; i <= N; i++) {			// min_dp 값 구하기
		left = min(dp[i - 1][0], dp[i - 1][1]);
		right = min(dp[i - 1][1], dp[i - 1][2]);

		dp[i][0] = left + map[i][0] - '0';
		dp[i][1] = min(left, right) + map[i][1] - '0';
		dp[i][2] = right + map[i][2] - '0';
	}
	cout << min(min(dp[N][0], dp[N][1]), dp[N][2]);
}