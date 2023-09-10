#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long>m;

long long check(long long N) {
	if (m[N] == 0) {
		return N;
	}
	else {
		return m[N] = check(m[N]);
	}
}

vector<long long>solution(long long k, vector<long long>room_number) {
	vector<long long>answer;
	for (long long i = 0; i < room_number.size(); i++) {
		long long result = check(room_number[i]);
		answer.push_back(result);
		m[result] = result + 1;
	}
	return answer;
}