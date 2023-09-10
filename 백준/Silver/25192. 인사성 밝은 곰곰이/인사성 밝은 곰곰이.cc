#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main() {
	int N;
	cin >> N;
	int answer = 0;
	map<string, int>m;
	while (N--) {
		string str;
		cin >> str;
		if (str == "ENTER") {
			answer += m.size();
			m.clear();
		}
		else {
			m[str]++;
		}
	}
	if (m.size() != 0) {
		answer += m.size();
	}
	cout << answer;
}