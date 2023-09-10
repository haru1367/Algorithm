#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
int main() {
	int N;
	cin >> N;
	int sum = 0;
	int arr[8001] = { 0 };
	int max = 0;
	vector<int>num;
	queue<int>many;
	for (int i = 1; i <= N; i++) {
		int k;
		cin >> k;
		sum += k;
		num.push_back(k);
		arr[k + 4000]++;
		if (arr[k + 4000] > max) {
			max = arr[k + 4000];
		}
	}
	sort(num.begin(),num.end());
	for (int i = 0; i <= 8000; i++) {
		if (arr[i] == max) {
			many.push(i - 4000);
		}
	}
	if (many.size() >= 2) {
		many.pop();
	}
	cout << fixed;
	cout.precision(0);
	double beta = (double)sum / (double)N;
	cout << floor(beta+0.5) << endl;
	cout << num[(N - 1) / 2] << endl;
	cout << many.front() << endl;
	cout << num[num.size() - 1] - num[0] << endl;
	

}