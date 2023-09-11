#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>solution(int n, long long left, long long right) {
	vector<int>answer;
	for (long long a = left; a <= right; a++) {
		int i = a / n;
		int j = a % n;
		answer.push_back(max(i, j) + 1);
	}
	return answer;
	
}