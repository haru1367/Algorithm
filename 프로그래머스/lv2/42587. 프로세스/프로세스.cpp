#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int solution(vector<int>priorities, int location) {
	int answer = 1;
	queue<pair<int, int>>printer;
	for (int i = 0; i < priorities.size(); i++) {
		printer.push(make_pair(priorities[i], i));
	}
	
	stack<pair<int, int>>wait;
	while (wait.size() < priorities.size()) {
		queue<pair<int, int>>reset = printer;
		vector<pair<int, int>>num;
		for (int i = 0; i < printer.size(); i++) {
			num.push_back(reset.front());
			reset.pop();
		}
		pair<int, int>type = { 0,0 };
		for (int i = 1; i < num.size(); i++) {
			if (num[0].first < num[i].first) {
				type = num[0];
				break;
			}
		}
		if (type ==num[0]) {
			for (int i = 0; i < num.size() - 1; i++) {
				num[i] = num[i + 1];
			}
			num[num.size() - 1] = type;
			printer.push(printer.front());
			printer.pop();
			
		}
		else if (type == pair<int,int>{0, 0}) {
			wait.push(num[0]);
			printer.pop();
		}
	}
	int k = wait.size();
	vector<pair<int, int>>result;
	for (int i = 0; i < k; i++) {
		result.push_back(wait.top());
		wait.pop();
	}
	for (int j = 0; j < result.size(); j++) {
		if (result[result.size() - 1 - j].second == location) {
			answer = j + 1;
		}
	}
	return answer;
}