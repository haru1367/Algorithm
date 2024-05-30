def solution(d, budget):
    answer = 0
    s = sorted(d)
    sum = 0
    for i in range(0,len(s)):
        sum += s[i]
        if sum > budget:
            return i
        elif sum == budget:
            return i+1
    return len(s)