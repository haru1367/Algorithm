#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>

using namespace std;

int result = 0;  // 최종 결과를 저장할 변수

// 게임 보드와 그 크기를 저장할 변수들
char board[21][21];
bool visit[26] = { false };
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int R, C;

// 깊이 우선 탐색 함수 (DFS)
void dfs(int a, int b, int cnt) {
    for (int i = 0; i < 4; i++) {
        int nx = a + dx[i];
        int ny = b + dy[i];
        if (nx < 0 || ny < 0 || nx == R || ny == C || visit[board[nx][ny] - 'A'] == true) {
            result = max(result, cnt);
            continue;
        }
        else {
            visit[board[nx][ny] - 'A'] = true;
            dfs(nx, ny, cnt+1);
            visit[board[nx][ny] - 'A'] = false;
        }
    }

}

int main() {
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> R >> C;  // 보드 크기 입력

    // 보드의 문자열 입력
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }
    visit[board[0][0]-'A'] = true;
    dfs(0, 0, 1);  // DFS 함수 호출
    cout << result;
}