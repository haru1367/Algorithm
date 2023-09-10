#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		string str;
		getline(cin, str);
		if (str == ".") {
			break;
		}
		stack<char>kk;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(' || str[i] == '[') {
				kk.push(str[i]);
			}
			else if (str[i] == ')') {
				if (!kk.empty()) {
					if (kk.top() == '(') {
						kk.pop();
					}
					else {
						kk.push(')');
					}
				}
				else {
					kk.push(')');
				}
			}
			else if (str[i] == ']') {
				if (!kk.empty()) {
					if (kk.top() == '[') {
						kk.pop();
					}
					else {
						kk.push(']');
					}
				}
				else {
					kk.push(']');
				}
			}
		}
		if (kk.empty()) {
			cout << "yes" << '\n';
		}
		else {
			cout << "no" << '\n';
		}
	}
}