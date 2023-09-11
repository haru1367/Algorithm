#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

bool compare(pair<int,int>a , pair<int,int>b) {
	return a.second > b.second;
}

vector<int>solution(string s) {
	vector<int>answer;
	string tmp="";
	vector<int>num;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 48 && s[i] <= 57) {
			tmp += s[i];
		}
		else {
			if (s[i] == '{' && !tmp.empty()) {
				num.push_back(stoi(tmp));
				tmp = "";
			}
			else if (s[i] == '}' && !tmp.empty()) {
				num.push_back(stoi(tmp));
				tmp = "";

			}
			else if (s[i] == ',' && !tmp.empty()) {
				num.push_back(stoi(tmp));
				tmp = "";
			}
		}
	}
	vector<int>num1 = num;
	sort(num.begin(), num.end());
	num.erase(unique(num.begin(), num.end()), num.end());
	vector<pair<int,int>>count;
	for (int i = 0; i < num.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < num1.size(); j++) {
			if (num[i] == num1[j]) {
				cnt++;
			}
		}
		count.push_back(make_pair(num[i], cnt));
	}
	sort(count.begin(), count.end(), compare);
	for (int i = 0; i < count.size(); i++) {
		answer.push_back(count[i].first);
	}
	return answer;
}