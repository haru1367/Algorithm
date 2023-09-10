#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for (int i = 0; i < puddles.size(); i++) {
        arr[puddles[i][0]-1][puddles[i][1]-1] = -1;
    }
    int index = 0;
    while (arr[0][index] != -1) {
        arr[0][index] = 1;
        if (index == 100) {
            break;
        }
        index++;

    }
    index = 0;
    while (arr[index][0] != -1) {
        arr[index][0] = 1;
        if (index == 100) {
            break;
        }
        index++;
    }
    for (int i = 1; i < 101; i++) {
        for (int j = 1; j < 101; j++) {
            if (arr[i][j] == -1) {
                continue;
            }
            else {
                if (arr[i - 1][j] == -1 && arr[i][j-1] != -1) {
                    arr[i][j] = arr[i][j - 1];
                }
                else if (arr[i - 1][j] != -1 && arr[i][j - 1] == -1) {
                    arr[i][j] = arr[i - 1][j];
                }
                else if (arr[i - 1][j] == -1 && arr[i][j - 1] == -1) {
                    arr[i][j] = -1;
                }
                else {
                    arr[i][j] = (arr[i - 1][j] + arr[i][j - 1])%1000000007;
                }
            }
        }
    }
    answer = arr[m - 1][n - 1];

    return answer;
}