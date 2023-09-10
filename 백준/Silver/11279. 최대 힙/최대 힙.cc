#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int N;
	cin >> N;
	priority_queue<int,vector<int>,less<int>>q;
	while (N--) {
		int k;
		cin >> k;
		if (k != 0) {
			q.push(k);
		}
		else if (k == 0 && q.empty()) {
			printf("0\n");
		}
		else if (k==0 && !q.empty()) {
			printf("%d\n",q.top());
			q.pop();
		}
	}
}