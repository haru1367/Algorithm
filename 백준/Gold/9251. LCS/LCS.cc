#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int dp[1001][1001] = { 0 }; 
// 문자열1의 i 번째와 문자열2의 j번째 까지 비교했을때 LCS 문자열의 길이

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	string str1, str2;
	cin >> str1 >> str2; // 문자열 2개 입력받기

	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (str1[i - 1] == str2[j - 1]) {  // 비교하는 문자가 같을때
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {  // 다를 때
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); 
			}
		}
	}
	cout << dp[str1.size()][str2.size()];
	
}