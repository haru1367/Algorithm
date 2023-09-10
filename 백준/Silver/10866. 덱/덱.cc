#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	deque<int>q;
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		if (str == "push_back") {
			int k;
			cin >> k;
			q.push_back(k);
		}
		else if (str == "push_front") {
			int k;
			cin >> k;
			q.push_front(k);
		}
		else if (str == "pop_front") {
			if (!q.empty()) {
				cout << q.front() << '\n';
				q.pop_front();
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (str == "pop_back") {
			if (!q.empty()) {
				cout << q.back() << '\n';
				q.pop_back();
			}
			else {
				cout << -1 << '\n';
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
		else if (str == "front") {
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.front() << '\n';
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