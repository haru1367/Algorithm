#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num = 1;
	stack<int>save;
	vector<char>result;
	for (int i = 1; i <= N; i++) {
		int k;
		cin >> k;
		while (k >= num) {
			save.push(num);
			result.push_back('+');
			num++;
		}
		if (save.top() == k) {
			save.pop();
			result.push_back('-');
		}
		else {
			cout << "NO" << '\n';
			return 0;
		}
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << '\n';
	}
	
}