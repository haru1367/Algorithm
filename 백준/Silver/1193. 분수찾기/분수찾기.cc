#include <iostream>
using namespace std;
int main() {
	int X;
	cin >> X;
	if (X == 1) {
		cout << "1/1" << endl;
	}
	else {
		int i = 1;
		while (true) {
			if (X > (i * i + i) / 2 && X <= (i * i + 3 * i + 2) / 2) {
				int sum = i + 2;
				int k = X - (i * i + i) / 2;
				if (i % 2 == 1) {
					cout << k << "/" << sum-k << endl;
				}
				else {
					cout << sum - k << "/" << k << endl;
				}
				break;
			}
			i++;
		}
	}
}