#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<int> speak;
    vector<int>wordsizes;
    vector<int> samewords;
    vector<int> not_equals;
    int cnt = 0;
    int wordsize = 200;
    int not_equal = 200;
    int sameword = 200;

    for (int i = 0; i < words.size(); i++) {
        if (words[i].size() == 1) {
            wordsizes.push_back(i);
        }
    }
    if (wordsizes.size()>=1) {
        wordsize = wordsizes[0];
    }

    for (int i = 1; i < words.size(); i++) {
        for (int j = 0; j <i ; j++) {
            if (words[j] == words[i]) {
                samewords.push_back(i);
            }
        }
        
    }
    if (samewords.size() >=1) {
        sameword = samewords[0];
    }
   

    for (int i = 0; i < words.size() - 1; i++) {
        if (words[i][words[i].size() - 1] != words[i + 1][0]) {
           
            not_equals.push_back(i+1);
        }
    }
    if (not_equals.size()>=1) {
        not_equal = not_equals[0];
    }
    
    speak.push_back(wordsize);
    speak.push_back(sameword);
    speak.push_back(not_equal);


    if (wordsize == 200 && sameword == 200 && not_equal == 200) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        int min = *min_element(speak.begin(), speak.end());
        answer.push_back(min%n + 1);
        answer.push_back(min/n + 1);
    }
    
    return answer;
}