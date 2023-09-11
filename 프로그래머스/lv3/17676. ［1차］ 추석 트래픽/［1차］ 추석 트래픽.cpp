#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int solution(vector<string>lines) {
    if (lines.size()==1) {
        return 1;
    }
	int answer = 0;
	cout << fixed;
	cout.precision(3);
	vector<pair<double, double>>result;
	for (int i = 0; i < lines.size(); i++) {
		vector<string>info;
		stringstream ss(lines[i]);
		string str = "";
		while (ss >> str) {
			info.push_back(str);
		}
		string timemm = "";
		timemm += info[1][9];
		timemm += info[1][10];
		timemm += info[1][11];
		string times = "";
		times += info[1][6];
		times += info[1][7];
		string timem = "";
		timem += info[1][3];
		timem += info[1][4];
		string timeh = "";
		timeh += info[1][0];
		timeh += info[1][1];
		double time = stod(timemm)/1000 + stod(times) + stod(timem) * 60 + stod(timeh) * 3600;
		double take = stod(info[2]);
		result.push_back(make_pair(time - take + 0.001, time));
	}
	for (int i = 0; i < result.size()-1; i++) {
		int num = 1;
		for (int j = i + 1; j < result.size(); j++) {
			if (result[i].first + 1 >= result[j].first || result[i].second + 1 > result[j].first) {
				num++;
			}
		}
		answer = max(num, answer);
	}
	return answer;
}