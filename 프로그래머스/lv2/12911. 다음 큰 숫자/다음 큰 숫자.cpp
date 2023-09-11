#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	vector<int>n_two;
	int num1 = n;
	int n_count=0;
	for (int a = 0; a <= 30; a++) {
		n_two.push_back(num1 % 2);
		num1 = (num1 - num1 % 2) / 2;
		if (num1 == 0) {
			break;
		}
	}
	for (int b = 0; b < n_two.size(); b++) {
		if (n_two[b] == 1) {
			n_count += 1;
		}
	}
	
	int i;
	for (i = n+1; i <= 1000000; i++) {
		int j = i;
		int jcount = 0;
		for (int c = 0; c <= 30; c++) {
			if (j % 2 == 1) {
				jcount += 1;
			}
			j = (j - j % 2) / 2;
			if (j == 0) {
				break;
			}
		}
		if (jcount == n_count) {
			answer = i;
			break;
		}
	}
	
	return answer;
}