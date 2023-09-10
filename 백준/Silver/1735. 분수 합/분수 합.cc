#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int GCD(int a, int b)
{
    if (b == 0)return a;
    else return GCD(b, a % b);
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int down = b * d;
    int up = a * d + c * b;
    cout << up / GCD(down, up) << " " << down / GCD(down, up);
}