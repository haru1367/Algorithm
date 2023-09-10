#include <iostream>
#include <vector>
using namespace std;
int main() {
	int S, K;
	cin >> S >> K;
	vector<int>ss;
	for (int i = 1; i <= K; i++) {
		ss.push_back(S/K);
	}
	int remain = S % K;
	int index = ss.size() - 1;
	while (remain != 0) {
		ss[index]++;
		index--;
		remain--;
	}
	long long multi = 1;
	for (int i = 0; i < ss.size(); i++) {
		multi *= (long long)ss[i];
	}
	cout << multi << '\n';
	
}