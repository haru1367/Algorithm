#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;
int main() {
	int N;
	cin >> N;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		int num1=0;
		int num2 = 0;
		bool check = true;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '(') {
				num1++;
			}
			else {
				num2++;
			}
			if (num2 > num1) {
				check = false;
				break;
			}
		}
		if (num1 != num2) {
			check = false;
		}
		if (check == false) {
			cout << "NO" << '\n';
		}
		else {
			cout << "YES" << '\n';
		}
	}
}