#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cmath>


using namespace std;

vector<int>solution(vector<string>gems) {
	vector<int>answer;
	map<string, int>dic;
	for (int i = 0; i < gems.size(); i++) {
		dic[gems[i]]++;
	}
	int a = 0;
	int b = 0;
	int x = a;
	int y = b;
	int d = gems.size();
	map<string, int>m;
	m[gems[b]]++;
	while (true) {
		if (m.size() != dic.size()) {
			b++;
			if (b == gems.size()) {
				b--;
				break;
			}
			m[gems[b]]++;
		}
		else {
			if (d > b - a) {
				x = a;
				y = b;
				d = b - a;
			}
			m[gems[a]]--;
			if (m[gems[a]] == 0) {
				auto it = m.find(gems[a]);
				m.erase(it);
			}
			a++;
			if (a == gems.size() - dic.size()+1) {
				break;
			}
		}
		
	}
	answer.push_back(x + 1);
	answer.push_back(y + 1);
	
	return answer;
}