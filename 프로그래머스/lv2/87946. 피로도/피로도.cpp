#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<vector<int>>dungeons) {
	int answer = 0; 
	vector<pair<int, int>>ss;
	for (int i = 0; i < dungeons.size(); i++) {
		ss.push_back(make_pair(dungeons[i][0], dungeons[i][1]));
	}
	sort(ss.begin(), ss.end());
	vector<int>results;
	do {
		int piro = k;
		int result=0;
		for (int i = 0; i < ss.size(); i++) {
			if (piro >= ss[i].first) {
				piro -= ss[i].second;
				result++;
			}
			
		}
		results.push_back(result);

	} while (next_permutation(ss.begin(), ss.end()));
	answer = *max_element(results.begin(), results.end());
	return answer;
}