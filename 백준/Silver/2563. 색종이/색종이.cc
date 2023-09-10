#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int arr[100][100] = {0,};
	int k;
	cin >> k;
	for (int i = 1; i <= k; i++) {
		int a, b;
		cin >> a >> b;
		for (int x = a; x < a + 10; x++) {
			for (int y = b; y < b + 10; y++) {
				arr[x][y] = 1;
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (arr[i][j] == 1) {
				answer++;
			}
		}
	}
	cout << answer;
}