def solution(k, m, score):
    answer = 0
    score = sorted(score)
    trash = len(score)%m
    for i in range(trash,len(score),m):
        answer += score[i]*m
    return answer