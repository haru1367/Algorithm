#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N; // N*N보드판
int answer = 0;
int col[15];

void queen(int x) {
	if (N == x) {  // 모든 행에 배치가 가능한 경우 경우의수 +1
		answer++;
	}
	else {
		for (int i = 0; i < N; i++) {
			col[x] = i;
			bool check = true; // 퀸의 배치가 가능한지 체크
			for (int j = 0; j < x; j++) {
				if (col[x] == col[j] || abs(col[x] - col[j]) == x - j) {//같은 열에 있거나 대각선상에 있을때는 제외
					check = false;
					break;
				}
			}
			if (check == true) {
				queen(x + 1); // 배치가 가능할 시 다음 행으로 넘어감
			}
		}
	}
}

int solution(int n) {
    N = n;
    queen(0);
    return answer;
}