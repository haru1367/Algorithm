#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

vector<int>solution(string msg) {
	vector<int>answer;
	map<string, int>m;
	for (int i = 0; i < 26; i++) {
		string str = "";
		str += 65 + i;
		m.insert(make_pair(str, i+1));
	}
	int index = 0;
	string sstr = "";
	while (index < msg.size()) {
		string str = "";
		int search = index;
		while (search <= msg.size()) {
			str += msg[search];
			if (m.find(str) != m.end()) {
				sstr = str;
			}
			else {
				answer.push_back(m[sstr]);
				m.insert(make_pair(str, m.size() + 1));
				
				break;
			}
			search++;
			index++;
		}	
	}
	return answer;
}