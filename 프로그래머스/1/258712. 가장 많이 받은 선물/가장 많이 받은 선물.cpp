#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    map<pair<string, string>, int>gift; //선물내역 저장
    map<string, int>giftrate;//선물지수 저장
    for (int i = 0; i < gifts.size(); i++) {
        stringstream ss(gifts[i]);
        string str;
        vector<string>giver;
        while (getline(ss,str,' ')) {
            giver.push_back(str);
        }
        gift[{giver[0], giver[1]}]++;
        giftrate[giver[0]]++;
        giftrate[giver[1]]--;
    }

    map<string, int>result;
    for (int i = 0; i < friends.size()-1; i++) {
        for (int j = i+1; j < friends.size(); j++) {
            if (i == j) continue;
            else {
                if (gift[{friends[i], friends[j]}] > gift[{friends[j], friends[i]}]) {
                    result[friends[i]]++;
                }
                else if (gift[{friends[i], friends[j]}] < gift[{friends[j], friends[i]}]) {
                    result[friends[j]]++;
                }
                else if (gift[{friends[i], friends[j]}] == gift[{friends[j], friends[i]}]) {
                    if (giftrate[friends[i]] > giftrate[friends[j]]) {
                        result[friends[i]]++;
                    }
                    else if (giftrate[friends[i]] < giftrate[friends[j]]) {
                        result[friends[j]]++;
                    }
                }
            }
        }
    }
    for (auto k = result.begin(); k != result.end(); k++) {
        answer = max(answer, k->second);
    }
    return answer;
}