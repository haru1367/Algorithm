#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

bool primecheck(long long num) {
	for (long long i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	long long n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		long long k;
		cin >> k;
		if (k == 0 || k == 1) {
			cout << 2 << '\n';
		}
		else {
			while (primecheck(k) == false) {
				k++;
			}
			cout << k << '\n';
		}
	}
}