def solution(n):
    answer = 0
    result = []
    while n>0:
        result.append(n%3)
        n -= n%3
        n/=3
    result = result[::-1]
    print(result)
    for i in range(0,len(result)):
        answer += result[i] * (3**i)
    return answer