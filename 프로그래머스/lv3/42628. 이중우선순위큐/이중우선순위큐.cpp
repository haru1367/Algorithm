#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

vector<int>solution(vector<string>operations) {
	vector<int>answer;
	int a = 0;
	int b = 0;
	priority_queue<int>pq1;
	priority_queue<int,vector<int>,greater<int>>pq2;
	pq2.push(5);
	pq2.push(7);
	
	for (int i = 0; i < operations.size(); i++) {
		if (operations[i][0] == 'I') {
			a++;
			string s1 = operations[i].substr(1);
			pq1.push(stoi(s1));
			pq2.push(stoi(s1));
			
			
		}
		else {
			if (a == b) {
				continue;
			}
			if (operations[i][2] == '-') {
				pq2.pop();
			}
			else {
				pq1.pop();
			}
			b++;
		}
		if (a == b) {
			while (!pq1.empty()) {
				pq1.pop();
			}
			while (!pq2.empty()) {
				pq2.pop();
			}
		}

	}
	
	if (a == b) {
		answer = { 0,0 };
	}
	else {
		answer.push_back(pq1.top());
		answer.push_back(pq2.top());
	}
	
	return answer;
}