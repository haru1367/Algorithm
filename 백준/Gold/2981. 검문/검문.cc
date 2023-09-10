#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int gcd(int a, int b){
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		num.push_back(a);
	}
	sort(num.begin(), num.end());
	int GCD = num[1] - num[0];
	for (int i = 0; i < num.size() - 1; i++) {
		GCD = gcd(GCD, num[i + 1] - num[i]);
	}
	vector<int>result;
	result.push_back(GCD);
	for (int i = 2; i * i <= GCD; i++) {
		if (GCD % i == 0) {
			result.push_back(i);
			result.push_back(GCD / i);
		}
	}
	sort(result.begin(),result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << '\n';
	}
}