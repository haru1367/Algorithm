#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<pair<int, int>>kgcm;
	for (int i = 1; i <= N; i++) {
		int x, y;
		cin >> x >> y;
		kgcm.push_back(make_pair(x, y));
	}
	for (int i = 0; i < kgcm.size(); i++) {
		int score = 0;
		for (int j = 0; j < kgcm.size(); j++) {
			if (i == j) {
				continue;
			}
			if (kgcm[i].first < kgcm[j].first && kgcm[i].second < kgcm[j].second) {
				score++;
			}
		}
		cout << 1 + score << '\n';
		
	}

}