#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int solution(string s) {
	int answer=0;
	int t = 0;
	while (t < s.size()) {
		string str;
		for (int a = t + 1; a <= s.size() - 1; a++) {
			str += s[a];
		}
		for (int b = 0; b <= t; b++) {
			str += s[b];
		}
		
		stack<char>rotation;
		if (str[0] == '}' || str[0] == ']' || str[0] == ')') {
			t++;
		}
		else {
			rotation.push(str[0]);
			for (int i = 1; i < str.size(); i++) {
				if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
					rotation.push(str[i]);
				}
				else {
					if (!rotation.empty() && str[i] == ')' && rotation.top() == '(') {
						rotation.pop();
					}
					else if (!rotation.empty() && str[i] == '}' && rotation.top() == '{') {
						rotation.pop();
					}
					else if (!rotation.empty() && str[i] == ']' && rotation.top() == '[') {
						rotation.pop();
					}
				}
			}
			if (rotation.empty()) {
				answer++;
			}
			t++;
		}
	}
	return answer;
}