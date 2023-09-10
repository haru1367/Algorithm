#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<int, int>m;
	for (int i = 1; i <= N; i++) {
		int k;
		cin >> k;
		m[k]++;
	}
	int M;
	cin >> M;
	for (int i = 1; i <= M; i++) {
		int alpha;
		cin >> alpha;
		if (m.find(alpha) != m.end()) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
}