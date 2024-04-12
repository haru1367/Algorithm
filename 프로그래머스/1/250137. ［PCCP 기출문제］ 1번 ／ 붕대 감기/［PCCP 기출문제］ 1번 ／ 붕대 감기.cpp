#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>


using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int success = 0; // 연속 성공시간
    int status_health = health; // 현재체력
    int timeend = attacks[attacks.size() - 1][0];
    int index = 0;
    for (int i = 1; i <= timeend; i++) {
        if (i == attacks[index][0]) {
            status_health -= attacks[index][1];
            if (status_health <= 0) {
                return -1;
            }
            index++;
            success = 0;
        }
        else {
            success += 1;
            status_health += bandage[1];
            if (success == bandage[0]) {
                status_health += bandage[2];
                success = 0;
            }
            if (status_health >= health) {
                status_health = health;
            }
        }
    }
    return status_health;
}