#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int>citations) {
	int answer = 0;
	int csize = citations.size();
	int max = *max_element(citations.begin(), citations.end());
	for (int i = 0; i <= max; i++) {
		int a = 0;
		int b = 0;
		for (int j = 0; j < citations.size(); j++) {
			if (citations[j] >= i) {
				a++;
			}
			else if (citations[j] <= i) {
				b++;
			}
		}
		if (a >= i && b <= i) {
			answer = i;
		}
	}

	return answer;
}