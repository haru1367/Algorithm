def solution(n):
    answer = []
    while n>0:
        k = n%10
        answer.append(k)
        n-=k
        n/=10
    return answer