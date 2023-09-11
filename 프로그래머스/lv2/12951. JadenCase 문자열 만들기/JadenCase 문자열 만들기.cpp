#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
	string answer = "";
	
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 65 && s[i] <= 90) {
			s[i] = s[i] + 32;
		}
	}
	for (int j = 0; j< s.size(); j++) {

		if (s[j] == 32 && (s[j+1]>=97 && s[j+1]<=122)) {
			s[j+1] = s[j+1]-32;
		}
		
	}
	if (s[0] >= 97 && s[0] <= 122) {
		s[0] = s[0] - 32;
	}
	answer = s;
	return answer;
}