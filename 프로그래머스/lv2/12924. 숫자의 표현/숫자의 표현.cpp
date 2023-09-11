#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    int sum=0;
    int count = 0;
    for (int i = 1; i<150; i++) {
        for (int j = 1; j<=n; j++) {
            sum = j*i + (pow(i,2)-i)/2;
            if (sum == n) {
                count +=1;
                
            } else if (sum>n) {
                
                break;
            }
        }
    }
    answer = count;
    return answer;
}