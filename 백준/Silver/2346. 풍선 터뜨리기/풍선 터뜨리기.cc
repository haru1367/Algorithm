#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>
#include <cmath>

using namespace std;

int main() {
	cin.tie(0);
	int N;
	cin >> N;
	deque<pair<int, int>>pq;
	for (int i = 1; i <= N; i++) {
		int k;
		cin >> k;
		pq.push_back(make_pair(i, k));
	}

	while (!pq.empty()) {
		int k = pq.front().second;
		cout << pq.front().first << " ";
		pq.pop_front();
		if (pq.empty()) {
			break;
		}
		if (k > 0) {
			k--;
		}
		while (k!=0) {
			if (k > 0) {
				pair<int, int>q = pq.front();
				pq.pop_front();
				pq.push_back(q);
				k--;
			}
			else {
				pair<int, int>q = pq.back();
				pq.pop_back();
				pq.push_front(q);
				k++;
			}
		}
	}

}