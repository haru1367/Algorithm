def solution(n):
    answer = 0
    result = []
    while n>0:
        k = n%10
        result.append(k)
        n -= k
        n/=10
    result.sort()
    for i in range(0,len(result)):
        answer += 10**i * result[i]
    return answer