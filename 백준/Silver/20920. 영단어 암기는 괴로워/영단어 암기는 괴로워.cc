#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

bool compare(pair<string,int>a, pair<string,int>b) {
	if (a.second == b.second) {
		if (a.first.size() == b.first.size()) {
			return a.first < b.first;
		}
		else {
			return a.first.size() > b.first.size();
		}
	}
	else {
		return a.second > b.second;
	}
}

int main() {
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	map<string, int>m;
	while (N--) {
		string str;
		cin >> str;
		if (str.size() >= M) {
			m[str]++;
		}
	}
	vector<pair<string,int>>ss(m.begin(), m.end());
	sort(ss.begin(), ss.end(), compare);
	for (int i = 0; i < ss.size(); i++) {
		cout << ss[i].first << '\n';
	}

}