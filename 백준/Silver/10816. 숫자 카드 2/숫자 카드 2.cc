#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main() {
	int N;
	cin >> N;
	unordered_map<int, int>m;
	for (int i = 1; i <= N; i++) {
		int k;
		cin >> k;
		m[k]++;
	}
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int M;
	cin >> M;
	for (int i = 1; i <= M; i++) {
		int k;
		cin >> k;
		cout << m[k] << '\n';
	}
}