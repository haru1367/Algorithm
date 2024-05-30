def solution(s):
    answer = ''
    strlist = s.split(' ')
    result = []
    for i in range(0,len(strlist)):
        cs = []
        for j in range(0,len(strlist[i])):
            if j % 2 == 0 :
                cs.append(strlist[i][j].upper())
            else :
                cs.append(strlist[i][j].lower())
        result.append("".join(cs))
    answer = ' '.join(result)
    return answer