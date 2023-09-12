#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int dx[] = { 1,2,3,4,5,6 }; // 주사위를 던졌을 때 나오는 눈금의 종류
bool visit[101];

int main() {
	cout.tie(0);
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N,M;   // 사다리의 수 N, 뱀의 수 M
	cin >> N >> M;
	map<int,int>ladder;   // 사다리의 정보를 저장할 map
	map<int,int>snake;	  // 뱀의 정보를 저장할 map
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b; //사다리 시작점,끝점
		ladder[a] = b;
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b; //뱀 시작점, 끝점
		snake[a] = b;
	}
	queue<pair<int, int>>q; // 현재위치와 해당위치까지 오는데 던진 주사위의 수
	q.push(make_pair(1, 0)); // 초기 위치는 1번칸, 주사위 던진횟수 0
	visit[1] = true;  // 방문 체크

	while (!q.empty()) {  //bfs문
		int x = q.front().first;
		int y = q.front().second;
		visit[x] = true;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + 1;
			if (visit[nx] == true) {  //이미 방문한 칸이면 건너 뜀
				continue;
			}

			if (nx >= 100) {
				printf("%d", ny);  // 가장먼저 100번째 칸에 도착하면 result벡터에 횟수를 넣고 멈춤
				return 0;
			}
			else {
				if (ladder.find(nx) != ladder.end()) {  // 주사위를 던져 도착한 칸이 사다리일 경우
					q.push(make_pair(ladder[nx], ny));
				}
				else if (snake.find(nx) != snake.end()) { // 주사위를 던져 도착한 칸이 snake일 경우
					q.push(make_pair(snake[nx], ny));
				}
				else {  
					q.push(make_pair(nx, ny));  // 도착한 칸에 사다리와 뱀이 아무것도 없을 때
				}
				
			}
		}
	}
}