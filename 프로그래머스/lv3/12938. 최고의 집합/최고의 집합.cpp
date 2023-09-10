#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>solution(int n, int s) {
	vector<int>answer;
	int index = 0;
	if (s < n) {
		answer.push_back(-1);
		return answer;
	}

	while ((s - index) % n != 0) {
		index++;
	}
	vector<int>result;
	for (int i = 0; i < n; i++) {
		result.push_back((s - index) / n);
	}
	while (index > 0) {
		for (int i = 0; i < result.size(); i++) {
			result[i]++;
			index--;
			if (index == 0) {
				break;
			}
		}
	}
	sort(result.begin(), result.end());
	answer = result;
	return answer;
}