def solution(n, arr1, arr2):
    answer = []
    for i in range(0,n):
        number1 = arr1[i]
        number2 = arr2[i]
        number12=[]
        number22=[]
        while (number1>0):
            number12.append(int(number1%2))
            number1-=number1%2
            number1/=2
        while (number2>0):
            number22.append(int(number2%2))
            number2-=number2%2
            number2/=2
        while len(number12)<n:
            number12.append(0)
        while len(number22)<n:
            number22.append(0)
        number12.reverse()
        number22.reverse()
        result = ''
        for j in range(0,n):
            if number12[j] + number22[j] >=1:
                result +='#'
            else:
                result +=' '
        answer.append(result)
    return answer