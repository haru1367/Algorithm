#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    long int first;
    long int second;
    long int third;
    int a;
    int answer;
    first = 0;
    second = 1;
    
    
    for (a= 2; a<=n; a++) {
        third = (first%1234567 + second%1234567)%1234567;
        first = second;
        second = third;
    }
    answer = third%1234567;
   
    return answer;
}