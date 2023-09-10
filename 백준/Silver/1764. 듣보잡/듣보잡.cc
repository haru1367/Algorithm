#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	map<string, int>m;
	for (int i = 1; i <= N+M; i++) {
		string str;
		cin >> str;
		m[str]++;
	}
	vector<string>names;
	int num = 0;
	for (auto k = m.begin(); k != m.end(); k++) {
		if (k->second == 2) {
			num++;
			names.push_back(k->first);
		}
	}
    cout << num << endl;
	for (int i = 0; i < names.size(); i++) {
		cout << names[i] << '\n';
	}
	
}