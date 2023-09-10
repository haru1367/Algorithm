#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;
	map<string, int>m;
	for (int i = 0; i < n; i++) {
		string str, str1;
		cin >> str >> str1;
		if (str1 == "enter") {
			m[str] = 1;
		}
		else {
			m[str] = 0;
		}
	}
	vector<string>ss;
	for (auto k = m.begin(); k != m.end(); k++) {
		if (k->second == 1) {
			ss.push_back(k->first);
		}
	}
	for (int i = ss.size() - 1; i >= 0; i--) {
		cout << ss[i] << '\n';
	}
}