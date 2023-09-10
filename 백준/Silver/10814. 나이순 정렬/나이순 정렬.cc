#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, string>a, pair<int, string>b) {
	return a.first < b.first;
}

int main() {
	int N;
	cin >> N;
	vector<pair<int, string>>dic;
	for (int i = 1; i <= N; i++) {
		int age;
		string name;
		cin >> age >> name;
		dic.push_back(make_pair(age, name));
	}
	stable_sort(dic.begin(), dic.end(), compare);
	for (int i = 0; i < dic.size(); i++) {
		cout << dic[i].first << " " << dic[i].second << '\n';
	}

}