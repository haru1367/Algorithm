#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>


using namespace std;

vector<int>solution(vector<int>fees, vector<string> records) {
	vector<int>answer;
	vector<vector<string>>status;
	for (int i = 0; i < records.size(); i++) {
		stringstream ss(records[i]);
		string str;
		vector<string>status_;
		while (ss >> str) {
			status_.push_back(str);
		}
		status.push_back(status_);
	}
	
	vector<string>car_number;
	for (int i = 0; i < status.size(); i++) {
		car_number.push_back(status[i][1]);
	}
	sort(car_number.begin(), car_number.end());
	car_number.erase(unique(car_number.begin(), car_number.end()), car_number.end());
	for (int i = 0; i < car_number.size(); i++) {
		vector<string>car_inout;
		int cnt = 0;
		for (int j = 0; j < status.size(); j++) {
			if (car_number[i] == status[j][1]) {
				cnt++;
				car_inout.push_back(status[j][0]);
				
			}
		}
		if (cnt % 2 != 0) {
			car_inout.push_back("23:59");
		}
		
		int time = 0;
		for (int j = 0; j < car_inout.size(); j++) {
			if (j % 2 == 0) {
				int atime = 0;
				int btime = 0;
				string atimeh = "";
				string atimem = "";
				string btimeh = "";
				string btimem = "";
				atimeh += car_inout[j + 1][0];
				atimeh += car_inout[j + 1][1];
				atimem += car_inout[j + 1][3];
				atimem += car_inout[j + 1][4];

				atime = stoi(atimeh) * 60 + stoi(atimem);
				
				btimeh += car_inout[j][0];
				btimeh += car_inout[j][1];
				btimem += car_inout[j][3];
				btimem += car_inout[j][4];
				btime = stoi(btimeh) * 60 + stoi(btimem);
				time += atime - btime;

			}
			else {
				continue;
			}
			
		}
		if (time <= fees[0]) {
			answer.push_back(fees[1]);
		}
		else if (time > fees[0]) {
			answer.push_back(fees[1] + (int)ceil(((double)((double)time - (double)fees[0]) / (double)fees[2])) * (double)fees[3]);
		}
		
		
	}
	return answer;
}