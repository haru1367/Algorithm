#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int>num;
	for (int i = 1; i <= N; i++) {
		int k;
		cin >> k;
		num.push_back(k);
	}
	sort(num.begin(), num.end());
	for (int i = 0; i < num.size(); i++) {
		cout << num[i] << '\n';
	}
}