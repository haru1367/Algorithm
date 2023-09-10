#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	vector<char>s;
	string str, bomb;
	cin >> str >> bomb;
	string answer = "";
	for (int i = 0; i < str.size(); i++) {
		s.push_back(str[i]);
		if (s.size() >= bomb.size()) {
			bool check = true;
			for (int j = 0; j < bomb.size(); j++) {
				if (s[s.size() - bomb.size() + j] != bomb[j]) {
					check = false;
				}
			}
			if (check == true) {
				for (int j = 0; j < bomb.size(); j++) {
					s.pop_back();
				}
			}
		}
	}
	if (s.empty()) {
		cout << "FRULA";
	}
	else {
		for (int i = 0; i < s.size(); i++) {
			answer += s[i];
		}
		cout << answer;
	}
	
}