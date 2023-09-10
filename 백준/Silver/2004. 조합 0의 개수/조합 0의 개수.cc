#include <iostream>
#include <cmath>
using namespace std;

long long function(long long n, long long num) {
	long long cnt = 0;
	int k = num;
	while (num<=n) {
		cnt += (n / num);
		num *= k;
	}
	return cnt;
}

int main() {
	long long n, m;
	cin >> n >> m;
	cout << min(function(n, 2) - function(n - m, 2) - function(m, 2), function(n, 5) - function(n - m, 5) - function(m, 5)) << '\n';

}