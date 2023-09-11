#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		deque<int>dq;
		string order;
		cin >> order;
		int k;
		cin >> k;
		string arr;
		cin >> arr;
		string str = "";
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] >= 48 && arr[i] <= 57) {
				str += arr[i];
			}
			else if (str.size()!=0) {
				
				dq.push_back(stoi(str));
				str = "";
			}
		}
		bool check = true;
		int status = 0;
		for (int i = 0; i < order.size(); i++) {
			if (order[i] == 'R' && status == 0) {
				status = 1;
			}
			else if (order[i] == 'R' && status == 1) {
				status = 0;
			}
			else {
				if (dq.empty()) {
					printf("error\n");
					check = false;
					break;
				}
				else if (!dq.empty() && status == 0) {
					dq.pop_front();
				}
				else if (!dq.empty() && status == 1) {
					dq.pop_back();
				}
			}
		}
		if (check == true) {
			int dqsize = dq.size();
			printf("[");
			if (!dq.empty()) {
				if (dqsize == 1) {
					printf("%d", dq.front());
				} else if (status == 0 && dqsize>1) {
					for (int i = 0; i < dqsize - 1; i++) {
						printf("%d,", dq.front());
						dq.pop_front();
					}
					printf("%d", dq.front());
				} else if (status == 1&& dqsize >1) {
					for (int i = dq.size() - 2; i >= 0; i--) {
						printf("%d,", dq.back());
						dq.pop_back();
					}
					printf("%d", dq.back());
				}
			
			}
			printf("]\n");
		}
	}
}