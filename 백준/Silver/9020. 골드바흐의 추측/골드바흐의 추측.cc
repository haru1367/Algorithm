#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int i) {
	int rt;
	rt = sqrt(i);
	if (rt == 1 && i != 1) {
		return true;
	}
	if (i % 2) {
		for (int j = 2; j <= rt; j++) {
			if (!(i%j))
				return false;
			if (j == rt) {
				return true;
			}
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int alpha = 0; alpha < T; alpha++) {
		int n;
		cin >> n;

		for (int i = n / 2; i >= 2; i--) {
			if (isPrime(i) && isPrime(n - i)) {
				cout << i << " " << n - i << '\n';
				break;
			}
		}
	}
}