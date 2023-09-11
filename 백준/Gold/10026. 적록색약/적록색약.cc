#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int arr[101][101];
char arr1[101][101];
bool visit[101][101];
bool visit1[101][101];
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char c;
			cin >> c;
			arr1[i][j] = c;
			if (c == 'R' || c == 'G') {
				arr[i][j] = 1;
				
			}
			else {
				arr[i][j] = 2;
			}
			visit[i][j] = false;
		}
	}
	queue<pair<int, int>>q1;
	vector<int>answer1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit1[i][j] == false) {
				answer1.push_back(1);
				q1.push(make_pair(i, j));
				while (!q1.empty()) {
					int x = q1.front().first;
					int y = q1.front().second;
					q1.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx == -1 || ny == -1 || nx == N || ny == N || arr1[nx][ny] != arr1[x][y] || visit1[nx][ny] == true) {
							continue;
						}
						else if (arr1[nx][ny] == arr1[x][y]) {
							visit1[nx][ny] = true;
							q1.push(make_pair(nx, ny));
						}
					}
				}
			}

		}
	}
	cout << answer1.size() << '\n';

	queue<pair<int, int>>q;
	vector<int>answer;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] == false) {
				answer.push_back(1);
				q.push(make_pair(i, j));
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx == -1 || ny == -1 || nx == N || ny == N || arr[nx][ny] != arr[x][y] ||visit[nx][ny] == true) {
							continue;
						}
						else if (arr[nx][ny] == arr[x][y]) {
							visit[nx][ny] = true;
							q.push(make_pair(nx, ny));
						}
					}
				}
			}

		}
	}
	cout << answer.size() << '\n';
}