#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int n) {
    
    long long answer = 0;
    int first=1;
    int second=2;
    int third;
    int i;
    
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else if (n >=3) {
        for (i = 3; i<= 2000; i++) {
            first = first%1234567;
            second = second%1234567;
            
            third = first+ second;
            first = second;
            second = third;
            if (i == n) {
                answer = third%1234567;
                break;
            }
        }
        
    }
    return answer;
}