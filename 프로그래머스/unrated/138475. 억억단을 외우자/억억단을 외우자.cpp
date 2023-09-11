#include <string>
#include <vector>
#include <iostream>

using namespace std;

// e이하의 숫자에 대해서 각각 약수의 개수를 구해서 가장 많은 숫자가 답임
const int LIMIT = 5000001;
int counts[LIMIT];
int ans[LIMIT];

vector<int> solution(int e, vector<int> starts) {
  int size = starts.size();
  vector<int> answer(size);

  for (int i = 1; i <= e; i++) {
    ans[i] = i;
    for (int j = 1; j <= e / i; j++) {
      counts[i * j]++;
    }
  }

  for (int i = e - 1; i >= 1; i--) {
    if (counts[i] < counts[i + 1]) {
      counts[i] = counts[i + 1];
      ans[i] = ans[i + 1];
    }
  }

  for (int i = 0; i < size; i++) {
    answer[i] = ans[starts[i]];
  }

  return answer;
}