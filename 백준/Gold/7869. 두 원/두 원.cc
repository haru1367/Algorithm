#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define PI 3.14159265358979

using namespace std;

int main() {
	double x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	cout << fixed;
	cout.precision(8);
	double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if (r1 + r2 <= d) {
		cout << fixed;
		cout.precision(3);
		cout << 0.000 << '\n';
	}
	else if (d + min(r1, r2) <= max(r1, r2)) {
		cout << fixed;
		cout.precision(3);
		cout << min(r1, r2) * min(r1, r2) * PI << '\n';
	}
	else {
		double s = (r1 + r2 + d) / 2;
		double area = sqrt(s * (s - r1) * (s - r2) * (s - d));
		double h = 2 * area / d;
		double half_ceta = asin(h / r1);
		if (r2 * r2 > r1 * r1 + d * d) {
			half_ceta = PI - half_ceta;
		}
		double ceta = 2 * half_ceta;
		double a1 = ((1.0 / 2.0) * r1 * r1 * (ceta - sin(ceta)));
		half_ceta = asin(h / r2);
		if (r1 * r1 > r2 * r2 + d * d) {
			half_ceta = PI - half_ceta;
		}
		ceta = 2 * half_ceta;
		double a2 = ((1.0 / 2.0) * r2 * r2 * (ceta - sin(ceta)));
		cout << fixed;
		cout.precision(3);
		cout << a1 + a2 << '\n';
	}
}