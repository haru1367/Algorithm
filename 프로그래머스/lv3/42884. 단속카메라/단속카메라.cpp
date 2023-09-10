#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int solution(vector<vector<int>>routes) {
	int answer = 1;
	sort(routes.begin(), routes.end());
	int start = routes[0][1];
	int cnt = 0;
	for (int i = 1; i < routes.size(); i++) {
		if (routes[i][0] > start) {
			answer++;
			start = routes[i][1];
		}
		if (start >= routes[i][1]) {
			start = routes[i][1];
		}
	}
	return answer;
}