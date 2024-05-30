def solution(t,p):
    answer = 0
    k = len(p)
    for i in range(0,len(t)-k+1):
        str = t[i:i+k]
        if int(str) <= int(p):
            answer+=1

    return answer