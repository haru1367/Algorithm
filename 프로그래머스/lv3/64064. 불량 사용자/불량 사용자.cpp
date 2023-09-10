#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<string>user_id, vector<string>banned_id) {
	int answer = 0;
	
	sort(user_id.begin(), user_id.end());
	map<string, int>m;
	for (int i = 0; i < banned_id.size(); i++) {
		m[banned_id[i]]++;
	}
	vector<vector<string>>result;
	do {
		
		vector<string>user(user_id);
		vector<string>ss;
		for (int i = 0; i < banned_id.size(); i++) {
			if (banned_id[i].size() == user[i].size()) {
				for (int j = 0; j < user[i].size(); j++) {
					if (user[i][j] != banned_id[i][j]) {
						user[i][j] = '*';
					}
				}
				if (user[i] == banned_id[i]) {
					ss.push_back(user_id[i]);
				}
			}
		}
		if (ss.size() == banned_id.size()) {
			result.push_back(ss);
		}
	} while (next_permutation(user_id.begin(), user_id.end()));
	for (int i = 0; i < result.size(); i++) {
		sort(result[i].begin(), result[i].end());
	}
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	answer = result.size();
	return answer;
}