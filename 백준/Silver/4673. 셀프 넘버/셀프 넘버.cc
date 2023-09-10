#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<int, int>m;
void self(int n) {
	m[n]++;
	if (n < 10) {
		m[2 * n]++;
	}
	else {
		vector<int>k;
		int sum = n;
		while (n >= 10) {
			k.push_back(n % 10);
			n = (n - (n % 10)) / 10;
		}
		k.push_back(n);
		
		for (int i = 0; i < k.size(); i++) {
			sum += k[i];
		}
		m[sum]++;
	}
	return;
}

int main() {
	for (int i = 1; i <= 10000; i++) {
		self(i);
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second == 1 && it->first <10000) {
			cout << it->first << endl;
		}
	}
}