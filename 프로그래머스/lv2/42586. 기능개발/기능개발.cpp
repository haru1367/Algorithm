#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int>solution(vector<int>progresses, vector<int>speeds) {
	vector<int>answer;
	vector<pair<int, int>>ss;
	for (int i = 0; i < progresses.size(); i++) {
		int r = 100 - progresses[i];
		if (r % speeds[i] == 0) {
			r = r / speeds[i];
		}
		else {
			r = r / speeds[i] + 1;
		}
		ss.push_back(make_pair(i, r));
	}
	for (int i = 0; i < ss.size() - 1; i++) {
		for (int j = i + 1; j < ss.size(); j++) {
			if (ss[i].second > ss[j].second) {
				ss[j].second = ss[i].second;
			}
		}
	}
	vector<int>second;
	for (int i = 0; i < ss.size(); i++) {
		second.push_back(ss[i].second);
	}
	second.erase(unique(second.begin(), second.end()),second.end());
	for (int i = 0; i < second.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < ss.size(); j++) {
			if (second[i] == ss[j].second) {
				cnt++;
			}
		}
		answer.push_back(cnt);
	}
	
	return answer;
}