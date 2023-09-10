#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

long long payment(vector<int>block_move, long long floor, int P, int Q) {
	long long pay = 0;
	for (int i = 0; i < block_move.size(); i++) {
		long long ud = floor - block_move[i] > 0 ? P : -Q;
		pay += ud * (floor - block_move[i]);
	}
	return pay;
}

long long solution(vector<vector<int>>land, int P, int Q) {
	long long answer = -1;
	vector<int>block;
	for (int i = 0; i < land.size(); i++) {
		for (int j = 0; j < land.size(); j++) {
			block.push_back(land[i][j]);
		}
	}
	long long min = *min_element(block.begin(), block.end());
	long long max = *max_element(block.begin(), block.end());
	long long mid;
	while (min <= max) {
		mid = (min + max) / 2;
		if (min == max) {
			break;
		}
		long long pay1 = payment(block, mid, P, Q);
		long long pay2 = payment(block, mid + 1, P, Q);
		if (pay1 < pay2) {
			max = mid;
		}
		else if (pay1 > pay2) {
			min = mid + 1;
		}
		else {
			break;
		}
	}
	answer = payment(block, mid, P, Q);


	return answer;

}