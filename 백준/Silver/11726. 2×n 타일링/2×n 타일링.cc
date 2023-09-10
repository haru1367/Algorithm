#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int solution(int n) {
	int answer = 0;
	int first = 1;
	int second = 2;
	int index = 3;
	int third;
	if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 2;
	}
	else {
		while (index <= n) {
			third = (first + second) % 10007;
			first = second;
			second = third;
			index++;
		}
	}
	answer = third;
	return answer;
}
int main(){
    int N;
    cin>>N;
    cout << solution(N) <<'\n';
}