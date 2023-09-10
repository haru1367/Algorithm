#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	int T;
	cin >> T;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 1; i <= T; i++) {
		int startx, starty, endx, endy;
		cin >> startx >> starty >> endx >> endy;
		int M;
		cin >> M;
		int ans = 0;
		int in=0;
		int out=0;
		for (int i = 1; i <= M; i++) {
			int x, y, R;
			cin >> x >> y >> R;
			if ((x - startx) * (x - startx) + (y - starty) * (y - starty) < R * R) {
				if ((x - endx) * (x - endx) + (y - endy) * (y - endy) > R * R) {
					out++;
				}
			}
			else if ((x - startx) * (x - startx) + (y - starty) * (y - starty) > R * R) {
				if ((x - endx) * (x - endx) + (y - endy) * (y - endy) < R * R) {
					in++;
				}
			}
		}
		cout << in + out << '\n';
	}
}