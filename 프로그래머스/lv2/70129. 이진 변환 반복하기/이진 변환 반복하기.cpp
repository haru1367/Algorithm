#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>solution(string s) {
	vector<int>answer;
	string str1 = s;
	int count = 0;
	int cnt = 0;
	while (str1.size() >= 1) {
		string str;
		
		for (int i = 0; i < str1.size(); i++) {

			if (str1[i] == 49) {
				str += s[i];
			}
			else {
				count++;
			}
		}
		int strsize = str.size();
		
		vector<int>two;
		while (strsize > 0) {
			two.push_back(strsize % 2);
			strsize /= 2;
		}
		str.clear();
		for (int i = two.size() - 1; i >= 0; i--) {
			str += to_string(two[i]);

		}
		str1 = str;
		
		cnt++;
		
		
		if (str1 == "1") {
			break;
		}
	}
	answer.push_back(cnt);
	answer.push_back(count);


	return answer;
}