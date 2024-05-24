def solution(x,n):
    answer = []
    num = x
    answer.append(x)
    for i in range(1,n):
        x+=num
        answer.append(x)
    return answer