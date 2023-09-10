#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>>triangle) {
	int answer = 0;
	vector<vector<int>>sum(triangle.size(), vector<int>(triangle.size(), 0));
	sum[0][0] = triangle[0][0];
	for (int i = 1; i < sum.size(); i++) {
		sum[i][0] = sum[i - 1][0] + triangle[i][0];
		sum[i][i] = sum[i - 1][i - 1] + triangle[i][i];
	}
	for (int i = 2; i < sum.size(); i++) {
		for (int j = 1; j < i; j++) {
			sum[i][j] = max(sum[i - 1][j - 1], sum[i - 1][j]) + triangle[i][j];
		}
	}


	int max = *max_element(sum[sum.size()-1].begin(), sum[sum.size()-1].end());
	answer = max;
	return answer;
}