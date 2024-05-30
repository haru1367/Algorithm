def solution(s, n):
    answer = ''
    for i in range(0,len(s)):
        if ord(s[i])>=65 and ord(s[i])<=90:
            if ord(s[i])+n > 90:
                answer += chr(ord(s[i])+n - 26)
            else :
                answer += chr(ord(s[i])+n)
        elif ord(s[i]) >= 97 and ord(s[i]) <= 122:
            if ord(s[i])+n>122:
                answer += chr(ord(s[i])+n - 26)
            else:
                answer += chr(ord(s[i])+n)
        else :
            answer += ' '

    return answer