#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, k, n;
	char c;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> k;
		multiset<int> m;

		for (int j = 0; j < k; j++) {
			cin >> c >> n;
			if (c == 'I') {
				m.insert(n);
			}
			else {
				if (!m.empty() && n == -1) {
					m.erase(m.begin());
				}
				else if (!m.empty() && n == 1) {
					auto iter = m.end();
					iter--;
					m.erase(iter);
				}
			}
		}
		if (m.empty()) {
			cout << "EMPTY" << "\n";
		}
		else {
			auto it = m.end();
			it--;
			cout << *it << " " << *m.begin() << "\n";
		}
	}
	return 0;
}