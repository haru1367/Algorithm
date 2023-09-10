#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <tuple>

using namespace std;

int solution(vector<int>arrows) {
	int answer = 0;
	pair<int, int>point = { 0,0 };
	tuple<int, int, int, int>line;
	map<tuple<int, int, int, int>, int>m;
	map<pair<int, int>, int>vv;
	vv[point]++;
	for (int i = 0; i < arrows.size(); i++) {
		switch (arrows[i]) {
		case 0:
			point.second += 2;
			line = { point.first,point.second - 2,point.first,point.second };
			m[line] = 0;
			line = { point.first,point.second, point.first,point.second - 2 };
			m[line] = 4;
			break;
		case 1:
			point.first += 2;
			point.second += 2;
			line = { point.first - 2, point.second - 2, point.first,point.second };
			m[line] = 1;
			line = { point.first,point.second, point.first - 2,point.second - 2 };
			m[line] = 5;
			break;
		case 2:
			point.first += 2;
			line = { point.first - 2,point.second, point.first,point.second };
			m[line] = 2;
			line = { point.first, point.second, point.first - 2,point.second };
			m[line] = 6;
			break;
		case 3:
			point.first += 2;
			point.second -= 2;
			line = { point.first - 2,point.second + 2, point.first, point.second };
			m[line] = 3;
			line = { point.first, point.second, point.first - 2,point.second + 2 };
			m[line] = 7;
			break;
		case 4:
			point.second -= 2;
			line = { point.first,point.second + 2,point.first,point.second };
			m[line] = 4;
			line = { point.first,point.second,point.first,point.second + 2 };
			m[line] = 0;
			break;
		case 5:
			point.first -= 2;
			point.second -= 2;
			line = { point.first + 2,point.second + 2,point.first,point.second };
			m[line] = 5;
			line = { point.first,point.second,point.first + 2,point.second + 2 };
			m[line] = 1;
			break;
		case 6:
			point.first -= 2;
			line = { point.first + 2,point.second,point.first,point.second };
			m[line] = 6;
			line = { point.first,point.second,point.first + 2,point.second };
			m[line] = 2;
			break;
		case 7:
			point.first -= 2;
			point.second += 2;
			line = { point.first + 2,point.second - 2,point.first,point.second };
			m[line] = 7;
			line = { point.first, point.second,point.first + 2,point.second - 2 };
			m[line] = 3;
			break;
		}
		vv[point] ++;
	}
	int v = vv.size();
	int e = m.size() / 2;
	int vnumber = 0;
	
	for (auto k = m.begin(); k != m.end(); k++) {
		if (k->second == 1) {
			int x1 = get<0>(k->first) + 2;
			int y1 = get<1>(k->first);
			int x2 = get<0>(k->first);
			int y2 = get<1>(k->first) + 2;
			if (m.find({ x1,y1,x2,y2 }) != m.end()) {
				vnumber++;
			}

		}
		else if (k->second == 3) {
			int x1 = get<0>(k->first) + 2;
			int y1 = get<1>(k->first);
			int x2 = get<0>(k->first);
			int y2 = get<1>(k->first) -2;
			if (m.find({ x1,y1,x2,y2 }) != m.end()) {
				vnumber++;
			}
		}
		else if (k->second == 5) {
			int x1 = get<0>(k->first) - 2;
			int y1 = get<1>(k->first);
			int x2 = get<0>(k->first);
			int y2 = get<1>(k->first) - 2;
			if (m.find({ x1,y1,x2,y2 }) != m.end()) {
				vnumber++;
			}
		}
		else if (k->second == 7) {
			int x1 = get<0>(k->first) - 2;
			int y1 = get<1>(k->first);
			int x2 = get<0>(k->first);
			int y2 = get<1>(k->first) + 2;
			if (m.find({ x1,y1,x2,y2 }) != m.end()) {
				vnumber++;
			}
		}
	}
	
	vnumber /= 4;
	v += vnumber;
	e += vnumber * 2;
	answer = 1 - v + e;
	return answer;
}