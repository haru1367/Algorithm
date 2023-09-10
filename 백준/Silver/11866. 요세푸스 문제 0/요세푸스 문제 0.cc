#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	queue<int>q;
	queue<int>kk;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	while (!q.empty()) {
		for (int j = 1; j <= K - 1; j++) {
			int a = q.front();
			q.pop();
			q.push(a);
		}
		kk.push(q.front());
		q.pop();
	}
	cout << "<";
	for (int i = 1; i <= N - 1; i++) {
		cout << kk.front() << ", ";
		kk.pop();
	}
	cout << kk.front() << ">";
}