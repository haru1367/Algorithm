#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool check[201];

int dfs(vector<vector<int>>& computers, int current) {
	check[current] = 1;
	for (int i = 0; i < computers.size(); i++) {
		if (check[i] == 0 && computers[current][i] == 1) {
			dfs(computers, i);
		}
	}
	return 1;
}

int solution(int n, vector<vector<int>>computers) {
	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (check[i] == 0) {
			answer += dfs(computers, i);
		}
	}
	return answer;
}