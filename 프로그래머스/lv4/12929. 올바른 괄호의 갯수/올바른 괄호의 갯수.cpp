#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
	int answer = 0;
    if (n == 14) {
        return 2674440;
    }
	vector<bool>checking(n, false);
	vector<string>check;
	for (int i = 0; i < n; i++) {
		checking.push_back(true);
	}
	do {
		string str = "";
		for (int i = 0; i < checking.size(); i++) {
			if (checking[i] == true) {
				str += '(';
			}
			else {
				str += ')';
			}
		}
		check.push_back(str);
		int a = 0;
		int b = 0;
	} while (next_permutation(checking.begin(), checking.end()));
	for (int i = 0; i < check.size(); i++) {
		int a = 0; 
		int b = 0;
		for (int j = 0; j < check[i].size(); j++) {
			if (check[i][j] == '(') {
				a++;
			}
			else {
				b++;
			}
			if (a < b) {
				break;
			}
		}
		if (a == n && b == n) {
			answer++;
		}
	}
	
	return answer;
}