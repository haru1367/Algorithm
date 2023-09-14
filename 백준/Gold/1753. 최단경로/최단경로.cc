#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define INF 1000000000 // 10억

int V, E, K;
int u, v, w;
int weight, node, next_weight, next_node;
int ans[20001];
vector<pair<int, int>> vec[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
	cin >> V >> E >> K;

	for (int i = 1; i <= V; i++) ans[i] = INF;

	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		vec[u].push_back(pair<int, int>(v, w));
	}

	ans[K] = 0;
	pq.push(make_pair(0, K)); // 가중치 크기순서대로 넣기위해 (가중치,노드)으로 push

	while (!pq.empty())
	{
		weight = pq.top().first;
		node = pq.top().second;
		pq.pop();

		for (int i = 0; i < vec[node].size(); i++)
		{
			next_node = vec[node][i].first;
			next_weight = weight + vec[node][i].second;
			if (ans[next_node] > next_weight)
			{
				ans[next_node] = next_weight;
				pq.push(make_pair(next_weight, next_node));
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (ans[i] == INF) cout << "INF" << '\n';
		else cout << ans[i] << '\n';
	}
}