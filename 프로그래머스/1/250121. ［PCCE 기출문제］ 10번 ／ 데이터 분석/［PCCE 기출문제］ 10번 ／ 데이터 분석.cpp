#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

bool compare1(vector<int>a, vector<int>b) {
    return a[0] < b[0];
}
bool compare2(vector<int>a, vector<int>b) {
    return a[1] < b[1];
}
bool compare3(vector<int>a, vector<int>b) {
    return a[2] < b[2];
}
bool compare4(vector<int>a, vector<int>b) {
    return a[3] < b[3];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    tuple<int, int, int, int>datas;
    for (int i = 0; i < data.size(); i++) {
        if (ext == "code" && data[i][0] < val_ext) {
            answer.push_back(data[i]);
        }
        else if (ext == "date" && data[i][1] < val_ext) {
            answer.push_back(data[i]);
        }
        else if (ext == "maximum" && data[i][2] < val_ext) {
            answer.push_back(data[i]);
        }
        else if (ext == "remain" && data[i][3] < val_ext) {
            answer.push_back(data[i]);
        }
    }
    if (sort_by == "code") {
        sort(answer.begin(), answer.end(), compare1);
    }
    else if (sort_by == "date") {
        sort(answer.begin(), answer.end(), compare2);
    }
    else if (sort_by == "maximum") {
        sort(answer.begin(), answer.end(), compare3);
    }
    else {
        sort(answer.begin(), answer.end(), compare4);
    }

    return answer;
}