#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int>scovile,int K) {
	int answer = 0;
	priority_queue<int,vector<int>,greater<int>>ss(scovile.begin(),scovile.end());
	while (ss.size() > 1 && ss.top() < K) {
		int one = ss.top();
		ss.pop();
		int two = ss.top();
		ss.pop();
		ss.push(one + two * 2);
		answer++;
	}
	if (ss.top() < K) {
		return -1;
	}
	return answer;
}