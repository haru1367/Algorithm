#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int arr[1001][1001];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
int answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int M, N;
	cin >> M >> N;
	answer = 0;
	queue<pair<int, int>>q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int k;
			cin >> k;
			arr[i][j] = k;
			if (k == 1) {
				q.push(make_pair(i, j));
			}
		}
	}
	int index = 0;
	while (true) {
		queue<pair<int, int>>pq;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx == N || ny == M || nx == -1 || ny == -1) {
					continue;
				}
				else if (arr[nx][ny] == 0) {
					arr[nx][ny] = 1;
					pq.push(make_pair(nx, ny));
				}
			}
		}
		q = pq;
		if (pq.empty()) {
			break;
		}
		index++;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				index = -1;
				break;
			}
		}
	}
	cout << index;
}
