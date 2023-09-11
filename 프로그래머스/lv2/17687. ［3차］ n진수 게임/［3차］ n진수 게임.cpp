#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

string solution(int n, int t, int m, int p) { 
    string answer1 = "";
    string answer;
    vector<string>num;
    vector<int>re_num;
    string result;
    result += to_string(0);
    for (int i = 1; i < 100000; i++) {
        string str;
        string re_str;
        int number = i;
        do {
            
            if (number % n == 10) {
                str += 'A';
            }
            else if (number % n == 11) {
                str += 'B';
            }
            else if (number % n == 12) {
                str += 'C';
            }
            else if (number % n == 13) {
                str += 'D';
            }
            else if (number % n == 14) {
                str += 'E';
            }
            else if (number % n == 15) {
                str += 'F';
            }
            else {
                str += to_string(number % n);
            }
            number = (number - number % n) / n;
            
        } while (number > 0);
        for (int j = 0; j < str.size(); j++) {
            re_str += str[str.size() - j - 1];
        }
        result += re_str; 
        
    }
    for (int j = 0; j < result.size(); j++) {
        if (j % m == p - 1) {
            answer1 += result[j];
        }
    }
    for (int i = 0; i < t; i++) {
        answer += answer1[i];
    }

    return answer;
}