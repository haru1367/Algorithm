#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	long long N;
	cin >> N;
	long long sum = 0;
	long long cnt = 1;
	while (true) {
		if (sum > N) {
			cout << cnt-2 << '\n';
			return 0;
		} else if (sum ==N) {
            cout << cnt-1 << '\n';
            return 0;
        }
		sum += cnt;
		cnt++;
	}
}