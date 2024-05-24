def solution(x):
    n = x
    result = 0
    while x>0:
        k = x%10
        result += k
        x-=k
        x/=10
    if n%result == 0:
        return True
    else :
        return False