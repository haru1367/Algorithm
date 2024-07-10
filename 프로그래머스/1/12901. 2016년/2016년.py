def solution(a,b):
    answer=''
    arr = [0,31,29,31,30,31,30,31,31,30,31,30,31]
    day = 0
    for i in range(0,a):
        day += arr[i]
    day += b
    result =['THU','FRI','SAT','SUN','MON','TUE','WED']
    answer = result[int(day%7)]
    return answer