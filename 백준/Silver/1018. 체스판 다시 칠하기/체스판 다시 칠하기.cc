#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

char board[51][51];

int check1(string &str) {
	int result1 = 0;
	string str1 = "BWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWB";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != str1[i]) {
			result1++;
		}
	}
	return result1;
}
int check2(string& str) {
	int result2 = 0;
	string str2 = "WBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBW";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != str2[i]) {
			result2++;
		}
	}
	return result2;
}
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	int answer = 64;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			string str = "";
			for (int a1 = i; a1 < i + 8; a1++) {
				for (int b1 = j; b1 < j + 8; b1++) {
					str += board[a1][b1];
				}
			}
			int k = min(check1(str), check2(str));
			answer = min(answer, k);
		}
	}
	cout << answer << endl;
}