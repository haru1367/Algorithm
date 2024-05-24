def solution(numbers):
    answer = 45
    for i in range(0,len(numbers)):
        answer -= numbers[i]
    return answer