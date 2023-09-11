#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>solution(int brown, int yellow) {
	vector<int>answer;
	int sum = brown + yellow;
	vector<int>num;
	for (int i = 2; i <= sum; i++) {
		if (sum % i == 0) {
			num.push_back(i);
		}
	}
	for (int i = num.size() - 1; i >= 0; i--) {
		if (brown == 2 * num[i] + 2 * (sum/num[i] - 2)) {
			answer.push_back(num[i]);
			answer.push_back(sum / num[i]);
			return answer;
		}
	}
}