#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool solution(string& str) {
	vector<int>num;
	vector<int>arr;
	for (int i = 0; i < str.size(); i++) {
		num.push_back(str[i] - 48);
	}
	for (int i = 0; i < num.size() - 1; i++) {
		arr.push_back(num[i + 1] - num[i]);
	}
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	if (arr.size() == 1) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int N;
	cin >> N;
	int result = 0;
	for (int i = 1; i <= N; i++) {
		string str = to_string(i);
		if (solution(str) == true) {
			result++;
		}
	}
	if (N >= 10) {
		result += 9;
	}
	else {
		result += N;
	}
	cout << result << endl;
}