#include <iostream>
#include <map>
using namespace std;
int main() {
	int A, B;
	cin >> A >> B;
	map<int, int>m;
	for (int i = 1; i <= A + B; i++) {
		int k;
		cin >> k;
		m[k]++;
	}
	int num = 0;
	for (auto k = m.begin(); k != m.end(); k++) {
		if (k->second == 1) {
			num++;
		}
	}
	cout << num << '\n';
}