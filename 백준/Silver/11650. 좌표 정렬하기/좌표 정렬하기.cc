#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first) return a.second < b.second;

	return a.first < b.first;
}
int main() {
	int N;
	cin >> N;
	vector<pair<int, int>>xy;
	for (int i = 1; i <= N; i++) {
		int x, y;
		cin >> x >> y;
		xy.push_back(make_pair(x, y));
	}
	sort(xy.begin(), xy.end(), compare);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < xy.size(); i++) {
		cout << xy[i].first << " " << xy[i].second << '\n';
	}
}