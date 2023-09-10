#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[1000001] = { 0, };

int main() {
	int T;
	cin >> T;
	for (int i = 2; i <= 1000000; i++) {
		arr[i] = i;
	}
	for (int i = 2; i * i <= 1000000; i++) {
		if (arr[i] == 0) {
			continue;
		}
		for (int j = i * i; j <= 1000000; j += i) {
			arr[j] = 0;
		}
	}
	while (T--) {
		int n;
		cin >> n;
		int cnt = 0;
		for (int i = 2; i < n; i++) {
			if (arr[n - i] + arr[i] == n) {
				cnt++;
				if (n - i == i) {
					cnt++;
				}
			}
		}
		cout << cnt / 2 << '\n';
	}
	return 0;
}