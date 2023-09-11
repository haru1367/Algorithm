#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int ans = 0;
	vector<int>num;
	for (int i = 0; i <= 30; i++) {
		num.push_back(n % 2);
		n = n / 2;
		if (n == 0) {
			break;
		}
	}
    vector<int>result;
	for (int i = 0; i < num.size(); i++) {
		if (num[i] == 1) {
			ans++;
		}
	}
	return ans;
}