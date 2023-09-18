#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main() {
	cout.tie(0);
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N; // N개의 점
	cin >> N;
	vector<pair<long long, long long>>point; // 각 점의 좌표를 저장할 벡터
	for (int i = 0; i < N; i++) {
		long long x, y;
		cin >> x >> y;
		point.push_back(make_pair(x, y));
	}
	point.push_back(point[0]); 
	// 헤론의 공식을 적용하기 위해 가장 처음 좌표를 한번 더 넣는다.
	double area = 0.0;
	for (int i = 0; i < point.size() - 1; i++) {
		long long k = point[i].first * point[i + 1].second - point[i].second * point[i + 1].first;
		area += (double)k;
	}
	area /= 2.0;
	if (area < 0) area *= -1;
	cout << fixed;
	cout.precision(1);
	cout << area << '\n';
}
