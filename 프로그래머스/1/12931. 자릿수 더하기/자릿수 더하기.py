def solution(N):
    answer =0
    while N>0:
        k = N%10
        answer += k
        N-=k
        N/=10
    return answer