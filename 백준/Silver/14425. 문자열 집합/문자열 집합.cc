#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	int ans = 0;
	unordered_map<string, int>dic;
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		dic[str]++;
	}
	for (int i = 1; i <= M; i++) {
		string str;
		cin >> str;
		if (dic.find(str) != dic.end()) {
			ans++;
		}
	}
	cout << ans << '\n';
}