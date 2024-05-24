def gcd(a,b):
    tmp = a%b
    while tmp!= 0:
        a = b
        b = tmp
        tmp = a%b
    return abs(b)

def solution(n,m):
    answer = [gcd(n,m),n*m/gcd(n,m)]
    return answer