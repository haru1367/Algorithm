#include <iostream>
#include <vector>

using namespace std;
 

int lcm(int a, int b) {
    int a1 = a;
    int b1 = b;
    int temp;
    int lcmnum;

    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }

    lcmnum = a1 * b1 / a;


    return lcmnum;
}

int solution(vector<int>arr) {
    int answer = 0;
    int max = lcm(1, arr[0]);
    for (int i = 1; i < arr.size(); i++) {
        max = lcm(max, arr[i]);
    }
    return max;
}