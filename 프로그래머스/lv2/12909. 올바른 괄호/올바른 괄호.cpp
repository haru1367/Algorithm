#include<string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int indexi = 0;
    int indexj = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            indexi++;
        } else if(s[i] == ')') {
            indexj++;
        }
        if (indexi < indexj) {
            return false;
        }

    }
    if (indexi != indexj) {
        return false;
    }
    return answer;
}