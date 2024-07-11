def solution(number,limit,power):
    answer =0
    for i in range(1, number+1):
        result = 0
        j=1
        while j*j<i:
            if i%j ==0:
                result+=2
            j+=1
        if j*j ==i:
            result+=1
        if result<=limit:
            answer+=result
        else:
            answer+=power
    return answer