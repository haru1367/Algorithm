#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(string s) {
	string answer = "";
	vector<int>num;
	stringstream ss(s);
	string str;
	while (ss >> str) {
		num.push_back(stoi(str));
	}
	int max = *max_element(num.begin(), num.end());
	int min = *min_element(num.begin(), num.end());
	answer += to_string(min);
	answer += " ";
	answer += to_string(max);

	return answer;
}