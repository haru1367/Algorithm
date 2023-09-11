#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int solution(int N, int A, int B) {
	int Num = N;
	int cnt = 0;
	do {
		Num = Num / 2;
		cnt++;
	} while (Num >= 1);
	cnt--;

	for (int i = 0; i < cnt; i++) {
		int A1 = ceil(A / pow(2, i + 1));
		int B1 = ceil(B / pow(2, i + 1));
		if (A1 == B1) {
			return i + 1;
		}
	}
}