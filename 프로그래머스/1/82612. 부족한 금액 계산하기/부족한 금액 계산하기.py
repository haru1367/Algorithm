def solution(price,money,count):
    result = 0
    for i in range(1,count+1):
        result += i
    if money - price*result >= 0:
        return 0
    else :
        return price*result - money