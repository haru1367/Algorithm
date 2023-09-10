#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	unordered_map<string, int>dic;
	string name[100001];
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		dic[str] = i;
		name[i] = str;

	}
	for (int i = 1; i <= M; i++) {
		string str;
		cin >> str;
		if (isdigit(str[0]) == true) {
			cout << name[stoi(str)] << '\n';
		}
		else {
			cout << dic[str] << '\n';
		}
		
	}
}