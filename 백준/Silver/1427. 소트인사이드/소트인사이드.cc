#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>num;
	while (N>0) {
		num.push_back(N % 10);
		N -= N % 10;
		N /= 10;
	}
	sort(num.begin(), num.end(), greater<int>());
	string str = "";
	for (int i = 0; i < num.size(); i++) {
		str += to_string(num[i]);
	}
	cout << stoi(str) << endl;

	
}