#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int solution(vector<int>elements) {
	int answer = 0;
	int k = elements.size();
	vector<int>result;
	while (k > 0) {
		vector<int>rotate(elements);
		for (int i = 0; i < k - 1; i++) {
			rotate.push_back(elements[i]);
		}
		for (int i = 0; i < elements.size(); i++) {
			int sum = 0;
			for (int j = 0; j < k; j++) {
				sum += rotate[i+j];
			}
			result.push_back(sum);
		}
		k--;
	}
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	answer = result.size();
	return answer;
}