#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int arr[1001][1001];

int solution(vector<vector<int>>board, vector<vector<int>>skill) {
	int answer = 0;
	for (int i = 0; i < skill.size(); i++) {
		int degree = skill[i][5];
		if (skill[i][0] == 1) degree = -degree;
		arr[skill[i][1]][skill[i][2]] += degree;
		arr[skill[i][3] + 1][skill[i][4] + 1] += degree;
		arr[skill[i][1]][skill[i][4] + 1] -= degree;
		arr[skill[i][3] + 1][skill[i][2]] -= degree;
	}

	for (int i = 0; i <= board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			arr[i][j + 1] += arr[i][j];
		}
	}
	for (int i = 0; i <= board[0].size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			arr[j + 1][i] += arr[j][i];
		}
	}
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			board[i][j] += arr[i][j];
			if (board[i][j] > 0) {
				answer++;
			}
		}
	}

	return answer;
}