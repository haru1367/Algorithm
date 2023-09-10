#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int N;
	int ans = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		bool check = true;
		str.erase(unique(str.begin(), str.end()), str.end());
		sort(str.begin(), str.end());
		for (int j = 0; j < str.size() - 1; j++) {
			if (str[j] == str[j + 1]) {
				check = false;
			}
		}
		if (check == true) {
			ans++;
		}
	}
	cout << ans << endl;
}