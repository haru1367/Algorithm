#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	queue<int>q;
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		if (str == "push") {
			int k;
			cin >> k;
			q.push(k);
		}
		else if (str == "front") {
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.front() << '\n';
			}
		}
		else if (str == "pop") {
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (str == "size") {
			cout << q.size() << '\n';
		}
		else if (str == "empty") {
			if (q.empty()) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (str == "back") {
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.back() << '\n';
			}
		}
	}
}