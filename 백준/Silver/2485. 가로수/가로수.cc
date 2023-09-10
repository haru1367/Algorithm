#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
	if (a < b)
		swap(a, b);
	return (a % b == 0 ? b : gcd(b, a % b));
}

int main(void)
{
	int n, res = 0;
	cin >> n;

	vector<int> v(n), diff;
	for (auto& i : v)
		cin >> i;

	for (int i = 0; i < n - 1; i++)
		diff.push_back(v[i + 1] - v[i]);

	int g = gcd(diff[0], diff[1]);
	for (int i = 2; i < diff.size(); i++)
		g = gcd(g, diff[i]);
;
	for (auto& i : diff)
		res += i / g - 1;

	cout << res << endl;
	return 0;
}  