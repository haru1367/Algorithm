#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, m, ans = 0;
    string str;
    cin >> n >> m >> str;
    for (int i = 1; i < str.size(); i++) {
        int count = 0;
        if (str[i - 1] == 'I') {
            while (str[i] == 'O' && str[i + 1] == 'I') {
                i += 2;
                count++;
                if (count == n) {
                    count--; 
                    ans++; 
                }
            }
        }
    }
    cout << ans << '\n';
}