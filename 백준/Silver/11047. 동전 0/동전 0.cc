#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	stack<int>aa;
	for (int i = 1; i <= N; i++) {
		int money;
		cin >> money;
		aa.push(money);
	}
	int ans = 0;
	while (K > 0) {
		if (aa.top()>K) {
			aa.pop();
		}
		else {
			ans += K / aa.top();
			K -= (K / aa.top()) * aa.top();
			aa.pop();
		}
	}
	cout << ans << '\n';
}