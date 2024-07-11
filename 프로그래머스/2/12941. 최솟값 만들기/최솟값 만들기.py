def solution(A,B):
    answer = 0
    A = sorted(A)
    B = sorted(B)
    if len(A) >= len(B):
        B = sorted(B,reverse = True)
        for i in range(0,len(B)):
            answer +=A[i] * B[i]
    else :
        A = sorted(A, reverse = True)
        for i in range(0,len(A)):
            answer += B[i] * A[i] 
    return answer