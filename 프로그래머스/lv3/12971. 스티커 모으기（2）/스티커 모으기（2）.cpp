#include <string>
#include <vector>
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int>sticker) {
	
	int answer = 0;
	int answer1 = 0;
	int answer2 = 0;
	int answer3 = 0;
	vector<int>dp(sticker.size(),0);
	
	if (sticker.size() == 1) {
		answer = sticker[0];
	}
	else if (sticker.size() == 2) {
		answer = max(sticker[0], sticker[1]);
	}
	else if (sticker.size() == 3) {
		answer = max(sticker[0], sticker[1]);
		answer = max(answer, sticker[2]);
		
	}
	else { 
		dp[0] = sticker[0];
		dp[1] = sticker[0];
		for (int i = 2; i < sticker.size() - 1; i++) {
			dp[i] = max(dp[i - 1], dp[i - 2] + sticker[i]);
			answer1 = dp[i];
		}
		vector<int>dp1(sticker.size(),0);
		dp1[0] = 0;
		dp1[1] = sticker[1];
		dp1[2] = sticker[1];
		for (int i = 3; i < sticker.size(); i++) {
			dp1[i] = max(dp1[i - 1], dp1[i - 2] + sticker[i]);
			answer2 = dp1[i];
		}
		vector<int>dp2(sticker.size(), 0);
		dp2[0] = 0;
		dp2[1] = 0;
		dp2[2] = sticker[2];
		dp2[3] = 0;
		for (int i = 4; i < sticker.size(); i++) {
			dp2[i] = max(dp2[i - 1], dp2[i - 2] + sticker[i]);
			answer3 = dp2[i];
		}

		answer = max(answer1, answer2);
		answer = max(answer, answer3);
	}
	return answer;
}