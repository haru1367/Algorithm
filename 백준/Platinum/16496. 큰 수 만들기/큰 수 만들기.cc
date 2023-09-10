#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(string a, string b) {
	return a + b > b + a;
}
string solution(vector<int>numbers) {
	string max;
	string answer;
	vector<string>number;
	for (int i = 0; i < numbers.size(); i++) {
		number.push_back(to_string(numbers[i]));
	}
	sort(number.begin(), number.end(), compare);
	for (int k = 0; k < number.size(); k++) {
		answer += number[k];

	}
	if (answer[0] == '0') {
		return "0";
	}
	return answer;
}
int main() {
	int N;
	cin >> N;
	vector<int>aa;
	for (int i = 1; i <= N; i++) {
		int k;
		cin >> k;
		aa.push_back(k);
	}
	cout << solution(aa) << '\n';
}