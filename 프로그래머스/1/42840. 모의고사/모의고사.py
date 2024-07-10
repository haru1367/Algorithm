def solution(answers):
    answer = []
    exam1 = [1,2,3,4,5]
    exam2 = [2,1,2,3,2,4,2,5]
    exam3 = [3,3,1,1,2,2,4,4,5,5]
    result1 = []
    result2 = []
    result3 = []
    for i in range(0,len(answers)):
        result1.append(exam1[int(i%len(exam1))])
        result2.append(exam2[int(i%len(exam2))])
        result3.append(exam3[int(i%len(exam3))])
    score1=0
    score2=0
    score3=0
    for i in range(0,len(answers)):
        if result1[i] == answers[i]:
            score1+=1
        if result2[i] == answers[i]:
            score2+=1
        if result3[i] == answers[i]:
            score3+=1
    a = max(score1,score2,score3)
    if a == score1:
        answer.append(1)
    if a == score2:
        answer.append(2)
    if a == score3:
        answer.append(3)
    return answer