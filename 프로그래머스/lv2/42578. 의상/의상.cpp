#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>>clothes) {
	int answer = 0;
	vector<string>kind;
	for (int i = 0; i < clothes.size(); i++) {
		kind.push_back(clothes[i][1]);
	}
	sort(kind.begin(), kind.end());
	kind.erase(unique(kind.begin(), kind.end()), kind.end());
	vector<int>order;
	for (int i = 0; i < kind.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < clothes.size(); j++) {
			if (kind[i] == clothes[j][1]) {
				cnt++;
			}
		}
		order.push_back(cnt);
	}
	int sum = 1;
	for (int i = 0; i < order.size(); i++) {
		sum *= (order[i] + 1);
	}
	answer = sum - 1;

	return answer;
}