#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

bool cmp(vector<int>a, vector<int>b) {
	return a[0] < b[0];
}

int solution(int n, vector<vector<int>>data) {
	int answer = 0;
	sort(data.begin(), data.end(), cmp);
	for (int i = 0; i < n-1; i++) {
		int x = data[i][0];
		int y = data[i][1];
		for (int j = i + 1; j < n; j++) {
			int xx = data[j][0];
			int yy = data[j][1];
			if (x == xx || y == yy) continue;
			int check = 1;
			int x1 = min(x, xx);
			int x2 = max(x, xx);
			int y1 = min(y, yy);
			int y2 = max(y, yy);
			for (int k = i+1; k <j; k++) {
				int cx = data[k][0];
				int cy = data[k][1];
				if (cx > x1 && cx<x2 && cy >y1 && cy < y2) {
					check = 0;
                    break;
				}
			}
			if (check == 1) {
				answer++;
			}
		}
		
	}
	return answer;
}