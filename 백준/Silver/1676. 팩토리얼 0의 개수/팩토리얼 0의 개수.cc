#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N; 
	int ans = 0;
	int num2 = 0;
	int num5 = 0;
	if (N >= 2) {
		for (int i = 2; i <= N; i++) {
			int k = i;
			while (k % 2 == 0 || k % 5 == 0) {
				if (k % 2 == 0) {
					num2++;
					k /= 2;
				}
				if (k % 5 == 0) {
					num5++;
					k /= 5;
				}
			}
		}
	}
	cout << min(num2, num5) << '\n';
}