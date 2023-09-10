#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<int>num;
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		int k;
		cin >> k;
		sum += k;
		num.push_back(sum);
	}
	while (M--) {
		int a, b;
		cin >> a >> b;
		if (a != 1) {
			cout << num[b - 1] - num[a - 2] << '\n';
		}
		else {
			cout << num[b - 1] << '\n';
		}
	}
}