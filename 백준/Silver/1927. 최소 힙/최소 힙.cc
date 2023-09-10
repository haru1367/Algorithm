#include <iostream>
#include <queue>
using namespace std;
int main() {
	int N;
	cin >> N; 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<long long, vector<long long>, greater<long long>>pq;
	for (int i = 1; i <= N; i++) {
		long long k;
		cin >> k;
		if (k == 0) {
			if (pq.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(k);
		}
	}
}