#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> stations, int w) {
    int answer = 0;
    int i=1;
    int index = 0;
    while (i <= n) {
        if (i >= stations[index] - w && i <= stations[index] + w) {
            i = stations[index] + w + 1;
            index++;
        }
        else {
            i += (w * 2) + 1;
            answer++;
        }
    }
    return answer;
}