#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	priority_queue<pair<int, int>>pq;
	for (int i = 1; i <= 8; i++) {
		int k;
		cin >> k;
		pq.push({ k,i });
	}
	int sum = 0;
	vector<int>num;
	for (int i = 0; i < 5; i++) {
		sum += pq.top().first;
		num.push_back(pq.top().second);
		pq.pop();
	}
	cout << sum << '\n';
	sort(num.begin(), num.end());
	for (int i = 0; i < num.size(); i++) {
		cout << num[i] << '\n';
	}
}