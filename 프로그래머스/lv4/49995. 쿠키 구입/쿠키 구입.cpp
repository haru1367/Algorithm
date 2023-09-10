#include <string>
#include <vector>
#include <iostream>


using namespace std;


int solution(vector<int>cookie) {
    int answer = 0;

    for (int num = 0; num < cookie.size() - 1; num++) {
        int leftsum = cookie[num];
        int rightsum = cookie[num + 1];
        int lindex = num;
        int rindex = num + 1;

        while (true) {
            if (leftsum == rightsum)
                answer = max(answer, leftsum);
            if (leftsum > rightsum) {
                if (rindex + 1 == cookie.size()) break;
                rightsum += cookie[++rindex];
            }
            else {
                if (lindex - 1 < 0) break;
                leftsum += cookie[--lindex];
            }

        }

    }
    return answer;
}