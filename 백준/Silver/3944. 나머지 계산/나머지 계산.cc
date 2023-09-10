#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 1; i <= N; i++) {
		int num;
		string k;
		cin >> num >> k;
		int sum = 0;
		for (int j = k.size() - 1; j >= 0; j--) {
			sum += k[j] - 48;
		}
		cout << sum % (num - 1) << '\n';
	}
}