#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int W, H, X, Y, P;
	cin >> W >> H >> X >> Y >> P;
	vector<pair<int, int>>status;
	for (int i = 1; i <= P; i++) {
		int a, b;
		cin >> a >> b;
		status.push_back(make_pair(a, b));
	}
	int ans = 0;
	for (int i = 0; i < status.size(); i++) {
		if (status[i].first < X && (X - status[i].first) * (X - status[i].first) + (Y + H / 2 - status[i].second) * (Y + H / 2 - status[i].second) <= H * H / 4) {
			ans++;
		}
		else if (status[i].first >= X && status[i].first <= X + W && status[i].second >= Y && status[i].second <= Y + H) {
			ans++;
		}
		else if (status[i].first > X + W && (status[i].first - X - W) * (status[i].first - X - W) + (status[i].second - Y - H / 2) * (status[i].second - Y - H / 2) <= H * H / 4) {
			ans++;
		}
	}
	cout << ans << '\n';
}