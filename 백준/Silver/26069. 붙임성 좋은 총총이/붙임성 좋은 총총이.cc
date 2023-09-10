#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {
	cin.tie(0);
	int N;
	cin >> N;
	map<string, bool>m;
	m["ChongChong"] = true;
	while (N--) {
		string str, str1;
		cin >> str >> str1;
		if (m.find(str1) != m.end() || m.find(str) != m.end()) {
			m[str1]=true;
			m[str]=true;
		}
	}
	cout << (int)m.size();
}