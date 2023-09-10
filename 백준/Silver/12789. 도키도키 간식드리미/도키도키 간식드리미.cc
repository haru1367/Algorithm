#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int main() {
	int N;
	cin >> N;
	stack<int>s;
	queue<int>q;
	int index = 1;
	vector<int>num;
	for (int i = 1; i <= N; i++) {
		int k;
		cin >> k;
		q.push(k);
	}
	while (!s.empty() || !q.empty()) {
		if (!q.empty() && q.front() == index) {
			q.pop();
			index++;
		}
		else if (!s.empty() && s.top() == index) {
			s.pop();
			index++;
		}
		else {
			if (!q.empty()) {
				s.push(q.front());
				q.pop();
			}
			else {
				break;
			}
		}
	}
	if (s.empty() && q.empty()) {
		cout << "Nice";
	}
	else {
		
		cout << "Sad";
	}
}