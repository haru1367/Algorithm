def solution(sizes):
    answer = 0
    a = 0
    b = 0
    for i in range(0,len(sizes)):
        a = max(a,sizes[i][0])
        a = max(a,sizes[i][1])
        k = min(sizes[i][0],sizes[i][1])
        b = max(b,k)
    answer = a*b
    return answer