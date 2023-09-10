#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>>edge) {
	int answer = 0;
	int from, to;
	vector<vector<int>>graph(n + 1);
	vector<int>dist(n + 1, -1);
	dist[1] = 0;
	for (int i = 0; i < edge.size(); i++) {
		from = edge[i][0];
		to = edge[i][1];
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	queue<int>q;
	q.push(1);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (dist[next] != -1) {
				continue;
			}
			dist[next] = dist[cur] + 1;
			q.push(next);
		}
	}
	sort(dist.begin(), dist.end(), greater<int>());
	int result = dist[0];
	for (int i = 0; i < dist.size() - 1; i++) {
		if (result == dist[i]) {
			answer++;
		}
	}
	return answer;
}
