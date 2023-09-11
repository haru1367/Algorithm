#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
	vector<char>stringstr1;
	vector<char>stringstr2;
	int answer = 0;

	for (int i = 0; i < str1.size(); i++) {
		stringstr1.push_back(str1[i]);
	}

	for (int i = 0; i < str2.size(); i++) {
		stringstr2.push_back(str2[i]);
	}

	for (int i = 0; i < stringstr1.size(); i++) {
		if (stringstr1[i] >= 65 && stringstr1[i] <= 90) {
			stringstr1[i] += 32;
		}
	}

	for (int i = 0; i < stringstr2.size(); i++) {
		if (stringstr2[i] >= 65 && stringstr2[i] <= 90) {
			stringstr2[i] += 32;
		}
	}

	vector<string>ch1;
	vector<string>ch2;

	for (int i = 0; i < stringstr1.size()-1; i++) {
		string st1;
		if ((stringstr1[i] >= 97 && stringstr1[i] <= 122) && (stringstr1[i + 1] >= 97 && stringstr1[i + 1] <= 122)) {
			st1 += stringstr1[i];
			st1 += stringstr1[i+1];
			ch1.push_back(st1);
		}
	}

	for (int i = 0; i < stringstr2.size() - 1; i++) {
		string st2;
		if ((stringstr2[i] >= 97 && stringstr2[i] <= 122) && (stringstr2[i + 1] >= 97 && stringstr2[i + 1] <= 122)) {
			st2 += stringstr2[i];
			st2 += stringstr2[i + 1];
			ch2.push_back(st2);
		}
	}

	int cnt = 0;
	for (int i = 0; i < ch1.size(); i++) {
		for (int j = 0; j < ch2.size(); j++) {
			if (ch1[i] == ch2[j]) {
				cnt += 1;
				ch1.erase(ch1.begin() + i);
				ch2.erase(ch2.begin() + j);
				i -= 1;
				j -= 1;
				break;
			}
		}
	}
	if (ch1.size() + ch2.size() + cnt == 0) {
		answer = 65536;
	}
	else {
		answer = ((double)(cnt) / (double)(ch1.size() + ch2.size() + cnt)) * 65536;
	}
	return answer;
}