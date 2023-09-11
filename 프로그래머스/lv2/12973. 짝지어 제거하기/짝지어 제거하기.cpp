#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int solution(string s) {
	int answer = 0;
	stack<char>twin;
	twin.push(s[0]);
	for (int i = 1; i < s.size(); i++) {
		if (!twin.empty() && s[i] == twin.top()) {
			twin.pop();
		}
		else {
			twin.push(s[i]);
		}
	}
	if (twin.empty()) {
		return 1;
	}
	else {
		return 0;
	}

	return answer;
}