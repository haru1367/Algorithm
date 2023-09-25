#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

int N, M;
int paper[101][101];
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };
map<pair<int, int>, int> m;

// 모든 치즈가 녹았는지 확인하는 함수
bool check() {
    bool checking = true;
    for (auto k = m.begin(); k != m.end(); k++) {
        if (k->second == 1) checking = false;
    }
    return checking;
}

// 치즈를 녹일지 결정하는 함수
void cheeze_check() {
    for (auto k = m.begin(); k != m.end(); k++) {
        int x = k->first.first;
        int y = k->first.second;
        int result = 0;
        if (paper[x - 1][y] == 3) result++;
        if (paper[x][y - 1] == 3) result++;
        if (paper[x + 1][y] == 3) result++;
        if (paper[x][y + 1] == 3) result++;
        if (result >= 2) {
            k->second = 0;  // 두 개 이상의 공기와 접촉한 치즈는 녹음
        }
    }
    for (auto k = m.begin(); k != m.end(); k++) {
        if (k->second == 0) paper[k->first.first][k->first.second] = 3;  // 치즈를 녹임
    }
}

// BFS를 사용하여 공기 확산을 처리하는 함수
void bfs() {
    bool visit[101][101] = { false };
    queue<pair<int, int>> q;
    q.push({ 0,0 });
    visit[0][0] = true;
    paper[0][0] = 3;  // 3은 공기를 나타냄
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx == N || ny == M || visit[nx][ny] == true ||
                paper[nx][ny] == 1) continue;
            else {
                paper[nx][ny] = 3;  // 공기 확산
                q.push({ nx,ny });
                visit[nx][ny] = true;
            }
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    int time = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> paper[i][j];
            if (paper[i][j] == 1) {
                m[{i, j}] = 1;  // 치즈의 위치를 맵에 저장
            }
        }
    }
    while (true) {
        bfs();
        if (check() == true) {
            cout << time << '\n';  // 모든 치즈가 녹았을 때 시간 출력
            break;
        }
        else {
            cheeze_check();  // 치즈를 녹이고 시간 증가
        }
        time++;
    }
}