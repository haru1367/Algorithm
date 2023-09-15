#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int room[51][51];
int new_room[51][51] = { 0 };
int sum = 0;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int R, C, T;
	cin >> R >> C >> T; //R,C : 격자의 크기 , T : 지난 시간
	vector<pair<int,int>>air;	//공기청정기의 위치를 저장할 벡터
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int a;
			cin >> a;
			room[i][j] = a;
			if (a == -1) {
				air.push_back(make_pair(i, j));
			}
		}
	}
	while (T--) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				int direct = 4;             //미세먼지가 확산할 방향의 개수
				bool checkup = true;
				bool checkdown = true;
				bool checkright = true;
				bool checkleft = true;
				if (room[i][j] == 0 || room[i][j] == -1) { // 해당 위치가 미세먼지가 없거나 공기청정기일때
					continue;
				}
				else {
					if (i == 0 ) {			//윗 방향이 막혀있을때
						direct--;
						checkup = false;
					}
					if (j == 0) {           //왼쪽 방향이 막혀있을 때
						direct--;
						checkleft = false;
					}
					if (i == R - 1) {		//아래 방향이 막혀있을 때
						direct--;
						checkdown = false;
					}
					if (j == C - 1) {		// 오른쪽 방향이 막혀있을 때
						direct--;
						checkright = false;
					}
					if (i > 0 && room[i - 1][j] == -1) {	//위쪽이 공기청정기일 때
						direct--;
						checkup = false;
					}
					if (j > 0 && room[i][j - 1] == -1) {    //왼쪽이 공기청정기일 때
						direct--;
						checkleft = false;
					}
					if (i < R - 1 && room[i + 1][j] == -1) {  // 아래쪽이 공기청정기일 때
						direct--;
						checkdown = false;
					}
					if (j < C - 1 && room[i][j + 1] == -1) { // 오른쪽이 공기청정기일 때
						direct--;
						checkright = false;
					}
				}
				if (checkup == true && room[i-1][j] != -1) {   // 위쪽으로 미세먼지가 확산
					new_room[i - 1][j] += room[i][j] / 5;
				}
				if (checkdown == true && room[i+1][j] != -1) {  // 아래쪽으로 미세먼지가 확산
					new_room[i + 1][j] += room[i][j] / 5;
				}
				if (checkright == true && room[i][j+1] != -1) {  // 오른쪽으로 미세먼지가 확산
					new_room[i][j + 1] += room[i][j] / 5;
				}
				if (checkleft == true && room[i][j-1] != -1) {   // 왼쪽으로 미세먼지가 확산
					new_room[i][j - 1] += room[i][j] / 5;
				}
				
				room[i][j] -= direct * (room[i][j] / 5);  // 확산한 미세먼지 만큼 해당 위치의 미세먼지 농도를 빼준다.
			}
		}
		for (int i = 0; i < R; i++) {				//미세먼지가 확산한 뒤 전체 업데이트
			for (int j = 0; j < C; j++) {
				room[i][j] += new_room[i][j];
				new_room[i][j] = 0;
			}
		}
		for (int i = air[0].first-1; i >= 1; i--) {		//위쪽 공기청정기가 돌아갈때
			room[i][0] = room[i - 1][0];
		}
		for (int j = air[0].second; j < C - 1; j++) {
			room[0][j] = room[0][j + 1];
		}
		for (int i = 0; i < air[0].first; i++) {
			room[i][C - 1] = room[i + 1][C - 1];
		}
		for (int j = C - 1; j > air[0].second + 1; j--) {
			room[air[0].first][j] = room[air[0].first][j - 1];
		}
		room[air[0].first][1] = 0;

		for (int i = air[1].first + 1; i < R - 1; i++) {	//아래쪽 공기청정기가 돌아갈 때
			room[i][0] = room[i + 1][0];
		}
		for (int j = 0; j < C - 1; j++) {
			room[R - 1][j] = room[R - 1][j + 1];
		}
		for (int i = R - 1; i > air[1].first; i--) {
			room[i][C - 1] = room[i - 1][C - 1];
		}
		for (int j = C - 1; j > air[1].second + 1; j--) {
			room[air[1].first][j] = room[air[1].first][j - 1];
		}
		room[air[1].first][1] = 0;	
	}
	for (int i = 0; i < R; i++) {						// 방안에 남아있는 전체 미세먼지 농도 계산
		for (int j = 0; j < C; j++) {
			sum += room[i][j];
		}
	}
	cout << sum + 2 << '\n';
}