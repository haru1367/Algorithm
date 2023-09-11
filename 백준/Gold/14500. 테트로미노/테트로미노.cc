#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[501][501];

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int k;
			cin >> k;
			arr[i][j] = k;
		}
	}
	vector<int>sum(19, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i <= N - 4) {
				sum[0] = max(sum[0], arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j]);
			}
			if (j <= M - 4) {
				sum[1] = max(sum[1], arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3]);
			}
			if (i <= N - 2 && j <= M - 2) {
				sum[2] = max(sum[2], arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1]);
				if (j >= 1) {
					sum[17] = max(sum[17], arr[i][j] + arr[i + 1][j - 1] + arr[i + 1][j] + arr[i + 1][j + 1]);
				}
			} 
			if (i <= N - 3 && j <= M - 2) {
				sum[3] = max(sum[3], arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j + 1]);
				sum[5] = max(sum[5], arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1]);
				sum[9] = max(sum[9], arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 2][j]);
				sum[11] = max(sum[11], arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1]);
				sum[18] = max(sum[18], arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j]);
			}
			if (i <= N - 2 && j <= M - 3) {
				sum[4] = max(sum[4], arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j]);
				sum[8] = max(sum[8], arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2]);
				sum[10] = max(sum[10], arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2]);
				sum[14] = max(sum[14], arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2]);
				sum[15] = max(sum[15], arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1]);
			}
			if (i <= N && j <= M - 2) {
				if (j >= 2) {
					sum[6] = max(sum[6], arr[i][j] + arr[i + 1][j - 2] + arr[i + 1][j - 1] + arr[i + 1][j]);
				}
			}
			if (i <= N - 3 && j <= M) {
				if (j >= 1) {
					sum[7] = max(sum[7], arr[i][j] + arr[i + 1][j] + arr[i + 2][j - 1] + arr[i + 2][j]);

					sum[13] = max(sum[13], arr[i][j] + arr[i + 1][j - 1] + arr[i + 1][j] + arr[i + 2][j - 1]);
					sum[16] = max(sum[16], arr[i][j] + arr[i + 1][j] + arr[i + 1][j - 1] + arr[i + 2][j]);
				}
			}
			if (i <= N - 2 && j <= M - 2) {
				if (j >= 1) {
					sum[12] = max(sum[12], arr[i][j] + arr[i][j + 1] + arr[i + 1][j - 1] + arr[i + 1][j]);
				}
			}
		}
	}
	cout << *max_element(sum.begin(), sum.end());
}