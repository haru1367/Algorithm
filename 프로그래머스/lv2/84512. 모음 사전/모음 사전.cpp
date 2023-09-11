#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(string word) {
    int answer = 0;
    vector<int>between = { 781,156,31,6,1 };
    vector<char>alpha = { 'A','E','I','O','U' };
    for (int i = 0; i < word.size(); i++) {
        for (int j = 0; j < alpha.size(); j++) {
            if (word[i] == alpha[j]) {
                answer += between[i] * j;
            }
        }
    }
    answer += word.size();
    return answer;
}