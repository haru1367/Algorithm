#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>

using namespace std;

int main() {
	cin.tie(0);
	int N;
	cin >> N;
	deque<int>q;
	while (N--) {
		int k;
		cin >> k;
		if (k == 1) {
			int a;
			cin >> a;
			q.push_front(a);
		}
		else if (k == 2) {
			int a;
			cin >> a;
			q.push_back(a);
		}
		else if (k == 3) {
			if (!q.empty()) {
				cout << q.front() << '\n';
				q.pop_front();
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (k == 4) {
			if (!q.empty()) {
				cout << q.back() << '\n';
				q.pop_back();
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (k == 5) {
			cout << q.size() << '\n';
		}
		else if (k == 6) {
			if (q.empty()) {
				cout << 1 << '\n';
			
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (k == 7) {
			if (!q.empty()) {
				cout << q.front() << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
		else {
			if (!q.empty()) {
				cout << q.back() << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
	}
}