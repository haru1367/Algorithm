#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	int M, N;
	cin >> M >> N;
	if (M <= 2 && N >= 2) {
		cout << 2 << endl;
	}
	if (M <= 3 && N >= 3) {
		cout << 3 << endl;
	}
	for (int i = M; i <= N; i++) {
		bool check = true;
		if (i >= 4) {
			for (int j = 2; j <= sqrt(i); j++) {
				if (i % j == 0) {
					check = false;
					break;
				}
			}
			if (check == true) {
				cout << i << '\n';
			}
			
		}
		
	}

}