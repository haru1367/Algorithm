#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int N;
	cin >> N;
	long long sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += i * (N / i);
	}
	cout << sum << '\n';
}