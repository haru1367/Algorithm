#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	cin >> str;
	int a = 0;
	int b = 0;
	if (str.find('x') != string::npos) {
		string str1 = "";
		int index = 0;
		while (str[index] != 'x') {
			str1 += str[index];
			index++;
		}
		a = stoi(str1);
		if (str.size() != str.find('x') + 1) {
			b = stoi(str.substr(str.find('x') + 1));
		}
		else {
			b = 0;
		}
	}
	else {
		a = 0;
		b = stoi(str);
	}

	string s2 = "";
	if (b > 0 && a != 0) {
		s2 += "+";
	}
	s2 += to_string(b);
	if (a != 0 && b == 1) {
		s2 = "+";
	}
	else if (a != 0 && b == -1) {
		s2 = "-";
	}
	else if (a == 0 && b == 1) {
		s2 = "";
	}
	else if (a == 0 && b == -1) {
		s2 = "-";
	}

	if (a != 0 && a != 2 && a != -2 && b != 0) {
		cout << a / 2 << "xx" << s2 << "x+W" << '\n';
	}
	else if (a != 0 && a != 2 && a != -2 && b == 0) {
		cout << a / 2 << "xx+W" << '\n';
	}
	else if (a == 0 && b != 0) {
		cout << s2 << "x+W" << '\n';
	}
	else if (a == 0 && b == 0) {
		cout << "W" << '\n';
	}
	else if (a == 2 && b != 0) {
		cout << "xx" << s2 << "x+W" << '\n';
	}
	else if (a == 2 && b == 0) {
		cout << "xx+W" << '\n';
	}
	else if (a == -2 && b == 0) {
		cout << "-xx+W" << '\n';
	}
	else if (a == -2 && b != 0) {
		cout << "-xx" << s2 << "x+W" << '\n';
	}

}