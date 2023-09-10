#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
	int N;
	cin >> N;
	stack<int>s;
	for (int i = 1; i <= N; i++) {
		int k;
		cin >> k;
		if (k == 1) {
			int a;
			cin >> a;
			s.push(a);
		}
		else if (k == 2) {
			if (s.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (k == 3) {
			cout << s.size() << '\n';
		}
		else if (k == 4) {
			if (s.empty()) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else {
			if (s.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << s.top() << '\n';
			}
		}
	}
}