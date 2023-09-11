#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string>change(vector<string>& cities) {
	for (int i = 0; i < cities.size(); i++) {
		for (int j = 0; j < cities[i].size(); j++) {
			if (cities[i][j] >= 65 && cities[i][j] <= 91) {
				cities[i][j] += 32;
			}
		}
	}
	return cities;
}

int solution(int cacheSize, vector<string>cities) {
	int answer = 5;
	vector<string>cache;
	vector<string>cities1 = change(cities);
	cache.push_back(cities[0]);
	if (cacheSize == 0) {
		answer = 0;
		for (int i = 0; i < cities.size(); i++) {
			answer += 5;
		}
	}
	else {
		for (int i = 1; i < cities1.size(); i++) {
			int cnt = 0;
			for (int j = 0; j < cache.size(); j++) {
				if (cities1[i] == cache[j]) {
					cache.erase(cache.begin() + j);
					cache.push_back(cities1[i]);
					answer += 1;
					break;
				}
				else {
					cnt++;
				}
			}
			if (cnt == cache.size()) {
				if (cache.size() == cacheSize) {
					cache.erase(cache.begin());
					cache.push_back(cities1[i]);
				}
				else {
					cache.push_back(cities1[i]);
				}
				answer += 5;
			}

		}
	}
	return answer;
}