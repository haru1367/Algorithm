#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t > 0) {
		t--;
		int a1, a2, r1, b1, b2, r2;
		cin >> a1;
		cin >> a2;
		cin >> r1;
		cin >> b1;
		cin >> b2;
		cin >> r2;
		double distance = (double)(sqrt(pow(b1 - a1, 2) + pow(b2 - a2, 2)));
		if (distance == 0 && r1 == r2) {
			cout << -1 << endl;
		}
		else if (distance < r1 + r2 && max(r1, r2) - min(r1, r2) < distance) {
			cout << 2 << endl;
		}
		else if (distance == r1 + r2 || max(r1, r2) - min(r1, r2) == distance) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
}