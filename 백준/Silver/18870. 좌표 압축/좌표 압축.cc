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
	vector<int>cnt(num);
	sort(cnt.begin(), cnt.end());
	cnt.erase(unique(cnt.begin(), cnt.end()), cnt.end());
	for (int i = 0; i < num.size(); i++) {
		auto it = lower_bound(cnt.begin(), cnt.end(), num[i]);
		cout << it - cnt.begin() << '\n';
	}
}