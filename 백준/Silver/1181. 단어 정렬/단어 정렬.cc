#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;
	} 
	return a.size() < b.size();
}

int main() {
	int N;
	cin >> N;
	vector<string>dic;
	for (int i = 1; i <= N; i++) {
		string str = "";
		cin >> str;
		dic.push_back(str);
	}
	sort(dic.begin(), dic.end());
	dic.erase(unique(dic.begin(), dic.end()), dic.end());
	sort(dic.begin(), dic.end(), compare);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < dic.size(); i++) {
		cout << dic[i] << '\n';
	}
}