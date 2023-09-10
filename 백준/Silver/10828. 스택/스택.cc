#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	stack<int>dic;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		if (str=="push") {
			int k;
			cin >> k;
			dic.push(k);
		}
		else if (str=="pop") {
			if (dic.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << dic.top() << '\n';
				dic.pop();
			}
		}
		else if (str=="size") {
			cout << dic.size() << '\n';
		}
		else if (str=="empty") {
			if (dic.empty()) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (str=="top") {
			if (dic.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << dic.top() << '\n';
			}
		}
	}
}