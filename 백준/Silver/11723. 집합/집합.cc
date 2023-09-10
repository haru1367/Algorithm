#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	map<int, int>m;
	int M;
	cin >> M;
	while (M--) {
		string str;
		cin >> str;
		if (str == "add") {
			int k;
			cin >> k;
			m[k]++;
		}
		else if (str == "remove") {
			int k;
			cin >> k;
			if (m.find(k) != m.end()) {
				m.erase(k);
			}
		}
		else if (str == "check") {
			int k;
			cin >> k;
			if (m.find(k) != m.end()) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if (str == "toggle") {
			int k;
			cin >> k;
			if (m.find(k) != m.end()) {
				m.erase(k);
			}
			else {
				m[k]++;
			}
		}
		else if (str == "all") {
			for (int i = 1; i <= 20; i++) {
				m[i]++;
			}
		}
		else if (str == "empty") {
			m.clear();
		}
	}
}