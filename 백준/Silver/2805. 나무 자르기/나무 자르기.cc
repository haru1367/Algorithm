#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long N, M;
	cin >> N >> M;
	vector<long long>tree;
	for (int i = 1; i <= N; i++) {
		long long k;
		cin >> k;
		tree.push_back(k);
	}
	long long minn = 0;
	long long maxn = *max_element(tree.begin(), tree.end());
	long long mid=0;
	long long result = 0;
	while (minn <= maxn) {
		long long sum = 0;
		mid = (minn + maxn) / 2;
		for (int i = 0; i < tree.size(); i++) {
			if (tree[i] > mid) {
				sum += tree[i] - mid;
			}
		}
		if (sum >= M) {
			result = mid;
			minn = mid+1;
		}
		else if (sum < M) {
			maxn = mid-1;
		}
	}
	cout << result << '\n';
}