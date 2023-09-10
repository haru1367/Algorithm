#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool bin_search(int a, int &k, vector<int>&stones) {
	int cnt = 0;
	for (int i = 0; i < stones.size(); i++) {
		if (stones[i] - a <= 0) {
			cnt++;
		}
		else {
			cnt = 0;
		}
		if (cnt >= k) {
			return true;
		}
	}
	return false;
}

int solution(vector<int>stones, int k) {
	int answer = 0;
	int min = 1;
	int max = *max_element(stones.begin(), stones.end());
	while (min <= max) {
		int mid = (min + max) / 2;
		if (bin_search(mid, k, stones)) {
			max = mid-1;
		}
		else {
			min = mid+1;
		}
	}
	answer = min;
	return answer;
}