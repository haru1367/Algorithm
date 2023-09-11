#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int arr[101][101][101];
int answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int M, N, H;
	cin >> M >> N >> H;
	answer = 0;
	queue<tuple<int,int,int>>q;
	vector<tuple<int, int, int>>direct = { {0,0,1},{0,0,-1},{1,0,0},{0,1,0},{-1,0,0},{0,-1,0} };

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {

				int num;
				cin >> num;
				arr[i][j][k] = num;
				if (num == 1) {
					q.push(make_tuple(i, j, k));
				}
			}
		}
	}
	int index = 0;
	while (true) {
		queue<tuple<int, int,int>>pq;
		while (!q.empty()) {
			int x = get<0>(q.front());
			int y = get<1>(q.front());
			int z = get<2>(q.front());
			q.pop();
			for (int i = 0; i < 6; i++) {
				int nx = x + get<0>(direct[i]);
				int ny = y + get<1>(direct[i]);
				int nz = z + get<2>(direct[i]);
				if (nx == N || ny == M || nz == H || nx == -1 || ny == -1 || nz == -1) {
					continue;
				}
				else if (arr[nx][ny][nz] == 0) {
					arr[nx][ny][nz] = 1;
					pq.push(make_tuple(nx, ny, nz));
				}
			}
		}
		q = pq;
		if (pq.empty()) {
			break;
		}
		index++;
	}
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j][k] == 0) {
					index = -1;
					break;
				}
			}
		}
	}
	cout << index;
}
