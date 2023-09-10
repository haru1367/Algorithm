#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	int N;
	cin >> N;
	vector<int>num;
	for (int i = 1; i <= N; i++) {
		int k;
		cin >> k;
		num.push_back(k);
	}
	int standard = num[0];
	for (int i = 1; i < num.size(); i++) {
		cout << num[0] / (gcd(num[0], num[i])) << "/" << num[i] / (gcd(num[0], num[i])) << '\n';
	}
}