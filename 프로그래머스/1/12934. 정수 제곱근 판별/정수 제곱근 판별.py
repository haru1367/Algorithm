def solution(n):
    if round(n**(1/2)) - n**(1/2) ==0:
        return (n**(1/2)+1)**2
    else :
        return -1