#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

long long solution(int n, vector<int>works) {
	long long answer = 0;
	long long sum = 0;
	for (int i = 0; i < works.size(); i++) {
		sum += works[i];
	}
	if (sum <= n) {
		return 0;
	}

	priority_queue<int>pq(works.begin(), works.end());
	while (n > 0) {
		int num = pq.top();
		pq.pop();
		pq.push(num-1);
		n--;
	}
	for (int i = 0; i < works.size(); i++) {
		answer += pow(pq.top(), 2);
		pq.pop();
	}
	return answer;
}