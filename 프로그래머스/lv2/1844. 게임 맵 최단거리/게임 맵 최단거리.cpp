#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<vector<int>>maps) {
	queue<pair<int, int>>board;
	board.push({ 0,0 });
	int dx[] = { 1,0,-1,0 };
	int dy[] = { 0,1,0,-1 };
	
	while (!board.empty()) {
		for (int i = 0; i < 4; i++) {
		    int coordx = board.front().first + dx[i];
			int coordy = board.front().second + dy[i];
			if (coordx >= 0 && coordx <= maps.size() - 1 && coordy >= 0 && coordy < maps[0].size() && maps[coordx][coordy] == 1) {
				board.push({ coordx,coordy });
				maps[coordx][coordy] = maps[board.front().first][board.front().second] + 1;
			
			}
		}
		board.pop();
	}
	return maps[maps.size() - 1][maps[0].size() - 1] == 1 ? -1 : maps[maps.size() - 1][maps[0].size() - 1];
	
}