#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

bool check_prime(long long alpha) {
	for (int i = 2; i <= (int)sqrt(alpha); i++) {
		if (alpha % i == 0) {
			return false;
		}
	}
	return true;
}

int solution(int n, int k) {
	int answer = 0;
	int num = n;
	vector<int>number;
	while (num > 0) {
		number.push_back(num % k);
		num = (num - num % k) / k;
	}
	string str="";
	for (int i = (int)number.size() - 1; i >= 0; i--) {
		str += to_string(number[i]);
	}
	string strstr="";
	
	
	stringstream ss(str);
	string token;
	while (getline(ss, token, '0')) {
		if (token.size() > 0 && token !="1") {
			if (check_prime(stoll(token)) == true) {
			
				answer++;
			}
		}
	}
	return answer;
}