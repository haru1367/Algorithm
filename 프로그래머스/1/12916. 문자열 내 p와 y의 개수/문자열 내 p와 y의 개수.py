def solution(s):
    countp = 0
    county = 0
    for i in s:
        if i == 'p'or i =='P':
            countp+=1
        elif i == 'y' or i == 'Y':
            county+=1
    if countp == county:
        return True
    else :
        return False