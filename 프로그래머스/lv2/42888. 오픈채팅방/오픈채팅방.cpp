#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <tuple>
#include <map>

using namespace std;

vector<string>solution(vector<string>record) {
	vector<string>answer;
	vector<tuple<string, string, string>>result;
	map<string, string>m;
	for (int i = 0; i < record.size(); i++) {
		if (record[i][0] == 'L') {
			record[i] += " unknown";
		}
		vector<string>inform;
		stringstream ss(record[i]);
		string str;
		while (ss >> str) {
			inform.push_back(str);
		}
		if (inform[0] == "Enter" || inform[0] == "Leave") {
			result.push_back(make_tuple(inform[0], inform[1], inform[2]));
		}
		if (inform[0] == "Enter" || inform[0] == "Change") {
			if (m.find(inform[1]) == m.end()) {
				m.insert(make_pair(inform[1], inform[2]));
			}
			else {
				m[inform[1]] = inform[2];
			}
		}
	}
	for (int i = 0; i < result.size(); i++) {
		string str="";
		if (get<0>(result[i]) == "Enter") {
			str += m[get<1>(result[i])];
			str += "님이 들어왔습니다.";
		}
		else {
			str += m[get<1>(result[i])];
			str += "님이 나갔습니다.";
		}
		answer.push_back(str);
	}
	return answer;
}