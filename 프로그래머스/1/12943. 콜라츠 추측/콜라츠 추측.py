def solution(n):
    answer = 0
    if n ==1 :
        return 0
    while answer<500:
        if n%2 == 0 :
            n/=2
        else:
            n= 3*n+1
        answer+=1
        if n==1:
            return answer
    return -1