#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
	int K;
	cin >> K;
	stack<int>num;
	for (int i = 1; i <= K; i++) {
		int a;
		cin >> a;
		if (a != 0) {
			num.push(a);
		}
		else {
			num.pop();
		}
	}
	int sum = 0;
	while (!num.empty()) {
		sum += num.top();
		num.pop();
	}
	cout << sum << '\n';
}