#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cout.precision(5);
	double sum = 0;
	double k = 0;
	for (int i = 0; i < 20; i++) {
		string str;
		double sub;
		
		string grade;
		cin >> str >> sub >> grade;
		k += sub;
		if (grade == "A+") sum += sub * 4.5;
		else if (grade == "A0") sum += sub * 4.0;
		else if (grade == "B+") sum += sub * 3.5;
		else if (grade == "B0") sum += sub * 3.0;
		else if (grade == "C+") sum += sub * 2.5;
		else if (grade == "C0") sum += sub * 2.0;
		else if (grade == "D+") sum += sub * 1.5;
		else if (grade == "D0") sum += sub * 1.0;
		else if (grade == "F") sum += 0;
		else if (grade == "P") k -= sub;
	}
	cout << sum / k;
}