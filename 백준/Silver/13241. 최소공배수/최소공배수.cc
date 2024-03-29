#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long GCD(long long a, long long b)
{
    if (b == 0)return a;
    else return GCD(b, a % b);
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << a * b / GCD(a, b);
}