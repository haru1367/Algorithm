#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int>>solution(vector<vector<int>>arr1, vector<vector<int>>arr2) {
	vector<vector<int>>answer(arr1.size(), vector<int>(arr2[0].size(),0));
	
	int arr1i = 0;
	int arr1j = 0;
	int arr2i = 0;
	int arr2j = 0;
	int cnt = 0;
	while (cnt < arr1.size() * arr2[0].size()) {
		int sum = 0;
		for (int k = 0; k < arr1[0].size(); k++) {
			sum += arr1[arr1i][k] * arr2[k][arr2j];
		}
		answer[arr1i][arr2j] = sum;
		
		arr2j++;
		if (arr2j == arr2[0].size()) {
			arr2j = 0;
			arr1i++;
		}
		cnt++;
	}
	
	return answer;
}