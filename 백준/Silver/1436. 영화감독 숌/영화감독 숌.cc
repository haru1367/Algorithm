#include <iostream>
#include <string>
using namespace std;
int main() {
	int N;
	cin >> N;
	int k = 0;
	int num = 1;
	while (true) {
		string str = to_string(num);
		if (str.find("666") != string::npos) {
			k++;
		}
		if (k == N) {
			cout << num << endl;
			break;
		}
		num++;
	}
}