def solution(n):
    answer = 1
    num = set(range(2,n+1))
    for i in range(2,1001):
        num -= set(range(2*i,n+1,i))
    answer = len(num)
    return answer