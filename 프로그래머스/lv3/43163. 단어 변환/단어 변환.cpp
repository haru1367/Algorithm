#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int result = 51;

void dfs(string beginer, string targeting, vector<bool>checking, vector<string>& words, int cnt = 0) {
	for (int i = 0; i < words.size(); i++) {
		int alpha = 0;
		for (int j = 0; j < words[i].size(); j++) {
			if (beginer[j] != words[i][j] && checking[i] == false) {
				alpha++;
			}
		}
		if (alpha == 1) {
			if (words[i] == targeting && result > cnt + 1) {
				result = cnt + 1;
				return;
			}
			checking[i] = true;
			dfs(words[i], targeting, checking, words, cnt+1);
			checking[i] = false;
		}
	}
}

int solution(string begin, string target, vector<string>words) {
	int answer = 0;
	vector<bool>check(words.size(), false);
	dfs(begin, target, check, words);
	if (result == 51) {
		return 0;
	}
	
	answer = result;
	return answer;
}