#include <iostream>
#include <vector>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<long long>m(10, 0);
	if (N == 1) {
		cout << 9 << '\n';
	}
	else {
		m[0] = 0;
		for (int i = 1; i <= 9; i++) {
			m[i] = 1;
		}
		for (int i = 2; i <= N; i++) {
			vector<long long>m1(10, 0);
			m1[0] += m[1];
			for (int j = 1; j <= 8; j++) {
				m1[j] = (m[j - 1] + m[j + 1])%1000000000;
			}
			m1[9] = m[8];
			m = m1;
		}
		long long sum = 0;
		for (int i = 0; i < m.size(); i++) {
			sum += m[i] % 1000000000;
		}
		cout << sum % 1000000000 << '\n';
	}
}
