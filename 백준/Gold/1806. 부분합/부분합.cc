#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int N, S;	// N : 입력받는 수의 개수 , S: 기준이 될 합
	cin >> N >> S;
	vector<int>vec; //누적합을 저장할 벡터
	vec.push_back(0);
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		sum += (long long)k;
		vec.push_back(sum);		//누적합을 벡터에 저장
	}
	int after = 0;				// 조회할 뒤쪽 인덱스
	int before = 0;				// 조회할 앞쪽 인덱스
	vector<int>sumsize;         // 누적합이 S보다 크거나 같을경우 해당 구간의 길이를 저장할 벡터
	if (vec.size() == 1 && vec[0] >= S) {
		cout << 1 << '\n';         // 입력받는 원소가 1개이고 그 값이 S보다 크거나 같을경우
	}
	else {
		while (true) {
			if (after == vec.size() - 1 && vec[after] - vec[before] < S) {
				break;   // 뒤쪽 인덱스가 누적합의 끝원소이고 before+1~ after구간의 합이 s보다 작으면 멈춤
			}
			if (vec[after] - vec[before] >= S) { // 구간의 합이 S보다 크거나 같을때
				int dist = after - before;
				before++;
				sumsize.push_back(dist);   // 구간의 길이를 벡터에 저장
			}
			else if (vec[after] - vec[before] < S) { // 구간의 합이 S보다 작을때
				after++;
			}
		}
		if (sumsize.empty()) {  // 구간의 합이 S를 넘길 수 없을때
			cout << 0 << '\n';
		}
		else {
			cout << *min_element(sumsize.begin(), sumsize.end());  //구간 길이의 최솟값 출력
		}
	}
}