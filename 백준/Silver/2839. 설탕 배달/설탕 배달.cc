#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	if (N % 5 == 0) {
		cout << N / 5 << endl;
	}
	else {
		int answer = 0;
		bool check = true;
		while (N % 5 != 0) {
			if (N < 3) {
				check = false;
				break;
			}
			N -= 3;
			answer++;
		}
		if (check == false) {
			cout << -1 << endl;
		}
		else {
			answer += N / 5;
			cout << answer << endl;
		}
	}
}