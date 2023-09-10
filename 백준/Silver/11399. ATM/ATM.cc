#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int>num;
	for (int i = 1; i <= N; i++) {
		int k;
		cin >> k;
		num.push_back(k);
	}
	sort(num.begin(), num.end());
	int snum = 0;
	vector<int>number;
	for (int i = 0; i < num.size(); i++) {
		number.push_back(snum + num[i]);
		snum += num[i];
	}
	int answer = 0;
	for (int i = 0; i < number.size(); i++) {
		answer += number[i];
	}
	cout << answer << '\n';
	return 0;
}