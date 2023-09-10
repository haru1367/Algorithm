#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	map<string, string>m;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < N; i++) {
		string site;
		string password;
		cin >> site >> password;
		m[site] = password;
	}
	for (int j = 0; j < M; j++) {
		string str;
		cin >> str;
		cout << m[str] << '\n';
	}
}