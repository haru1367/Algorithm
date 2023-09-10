#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int N, K;
		cin >> N >> K;
		long long answer = 1;
		int alpha = 1;
		for (int i = K; i > K - N; i--) {
			answer *= i;
			answer /= alpha;
			alpha++;
		}
		cout << answer << '\n';
	}
}
