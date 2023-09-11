#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<string>want, vector<int>number, vector<string>discount) {
	int answer = 0;
	
	for (int i = 0; i <= discount.size()-10; i++) {
		map<string, int>m;
		for (int j = 0; j < 10; j++) {
			m[discount[i + j]]++;
		}
		bool check = true;
		for (int j = 0; j < want.size(); j++) {
			if (m.find(want[j]) == m.end()) {
				check = false;
			}
			else {
				if (number[j] > m[want[j]]) {
					check = false;
				}
			}
		}
		if (check == true) {
			answer++;
		}
	}
	return answer;
}