def solution(food):
    answer = ''
    for i in range(1,len(food)):
        result = food[i]%2
        if result == 1:
            for j in range(0,int((food[i]-1)/2)):
                answer+=str(i)
        else :
            for j in range(0,int(food[i]/2)):
                answer+=str(i)
    answer +='0'
    ss=''
    for i in range(0,len(answer)-1):
        ss+=answer[len(answer)-2-i]
    answer += ss
    
    return answer