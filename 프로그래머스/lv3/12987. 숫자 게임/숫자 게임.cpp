#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    vector<int>array;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int Anumber = 0;
    for (int i = 0; i < B.size(); i++) {
        if (B[i] > A[Anumber]) {
            answer++;
            Anumber++;
        }
    }
    return answer;
}