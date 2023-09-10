#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
	string S;
	cin >> S;
	map<string, int>m;
	for (int i = 0; i < S.size(); i++) {
		string str = "";
		for (int j = 0; i+j<S.size(); j++) {
			str += S[i+j];
			m[str]++;
		}
		
	}
	cout << m.size() << '\n';
}