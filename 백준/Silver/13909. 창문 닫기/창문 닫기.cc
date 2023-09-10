#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	int index = 0;
	for (int i = 1; i * i <= n; i++) {
		index++;
	}
	cout << index;
}