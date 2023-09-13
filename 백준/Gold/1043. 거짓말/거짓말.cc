#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int graph[51][51];

int main() {
	cout.tie(0);
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M;				//N : 사람의 수 , M : 파티의 수
	cin >> N >> M;
	int num;
	cin >> num;				//num : 진실을 아는 사람의 수
	map<int, bool>truth;		//진실을 아는 사람을 저장할 map

	for (int i = 1; i <= N; i++) {
		truth[i] = false;		// 초기값 저장
	}

	for (int i = 0; i < num; i++) {
		int k;
		cin >> k;
		truth[k] = true;		// 진실을 아는 사람 저장
	}

	vector<vector<int>>human;   // 전체 파티 정보를 저장할 벡터
	while (M--) {
		vector<int>party;
		int k;
		cin >> k;
		for (int i = 0; i < k; i++) {
			int a;
			cin >> a;
			party.push_back(a);
		}
		human.push_back(party);
	}
	for (int k = 0; k < 50; k++) {
		for (int i = 0; i < human.size(); i++) {
			bool check = false;
			for (int j = 0; j < human[i].size(); j++) {
				if (truth[human[i][j]] == true) {
					check = true;
				}
			}
			if (check == true) {
				for (int j = 0; j < human[i].size(); j++) {
					truth[human[i][j]] = true;
				}
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < human.size(); i++) {
		bool check = false;
		for (int j = 0; j < human[i].size(); j++) {
			if (truth[human[i][j]] == true) {
				check = true;
			}
		}
		if (check == false) {
			answer++;
		}
	}
	cout << answer << '\n';
}