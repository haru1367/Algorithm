#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int N, M; // N*M 크기의 연구소
vector<vector<int>> lab; // 연구소의 상태를 저장하는 2차원 벡터
vector<pair<int, int>> space; // 빈 공간의 좌표를 저장하는 벡터
vector<pair<int, int>> virus; // 바이러스의 좌표를 저장하는 벡터
int dx[] = { -1, 0, 1, 0 }; // 상하좌우 이동을 위한 배열
int dy[] = { 0, 1, 0, -1 };
int answer = 0; // 최종 답을 저장하는 변수

// BFS 함수: 바이러스 확산 시뮬레이션
void bfs(vector<vector<int>> test) {
    int result = 0;
    queue<pair<int, int>> q;
    
    // 초기 바이러스 위치를 큐에 추가
    for (int i = 0; i < virus.size(); i++) {
        q.push(virus[i]);
    }
    
    // BFS 수행
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            
            // 범위를 벗어나거나 이미 감염되었거나 벽인 경우는 무시
            if (nx < 0 || ny < 0 || nx == N || ny == M || test[nx][ny] == 2 || test[nx][ny] == 1) continue;
            else {
                test[nx][ny] = 2; // 바이러스 감염 표시
                q.push({ nx, ny });
            }
        }
    }
    
    // 감염이 끝난 후, 남아 있는 빈 공간 개수를 계산
    for (int a = 0; a < N; a++) {
        for (int b = 0; b < M; b++) {
            if (test[a][b] == 0) {
                result++;
            }
        }
    }
    
    // 최대 격리 영역을 갱신
    if (answer < result) {
        answer = result;
    }
}

// 벽을 세우는 함수: 빈 공간에 벽을 3개 세우는 모든 조합을 시뮬레이션
void wall(vector<vector<int>> board) {
    for (int i = 0; i < space.size() - 2; i++) {
        for (int j = i + 1; j < space.size() - 1; j++) {
            for (int k = j + 1; k < space.size(); k++) {
                board[space[i].first][space[i].second] = 1; // 벽을 세우기
                board[space[j].first][space[j].second] = 1;
                board[space[k].first][space[k].second] = 1;
                bfs(board); // BFS로 바이러스 확산 시뮬레이션
                board[space[i].first][space[i].second] = 0; // 벽 제거
                board[space[j].first][space[j].second] = 0;
                board[space[k].first][space[k].second] = 0;
            }
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M; // 연구소 크기 입력
    
    // 연구소 초기 상태 입력
    for (int i = 0; i < N; i++) {
        vector<int> lab1;
        for (int j = 0; j < M; j++) {
            int k;
            cin >> k;
            lab1.push_back(k);
            
            // 빈 공간과 바이러스의 좌표 저장
            if (k == 0) {
                space.push_back(make_pair(i, j));
            }
            else if (k == 2) {
                virus.push_back(make_pair(i, j));
            }
        }
        lab.push_back(lab1);
    }
    
    wall(lab); // 벽을 세우고 최대 격리 영역 계산
    cout << answer << '\n'; // 결과 출력
}