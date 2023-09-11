#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool compare(pair<int, int>a, pair<int, int>b) {
	return a.second > b.second;
}

int solution(int k, vector<int>tangerine) {
	int answer = 0;
	map<int,int>m;
	for (int i = 0; i < tangerine.size(); i++) {
		m[tangerine[i]]++;
	}
	vector<pair<int, int>>pq(m.begin(), m.end());
	sort(pq.begin(), pq.end(), compare);
	int num = 0;
	while (num<k) {
		num += pq[answer].second;
		answer++;
	}
	return answer;
}