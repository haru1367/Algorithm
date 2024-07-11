def solution(nums):
    answer=0
    prime = []
    for i in range(2,3000):
        j = 2
        check = 0
        while j*j<=i:
            if i%j == 0:
                check = 1
                break
            j+=1
        if check == 0:
            prime.append(i)
    for i in range(0,len(nums)-2):
        for j in range(i+1,len(nums)-1):
            for k in range(j+1,len(nums)):
                if nums[i]+nums[j]+nums[k] in prime:
                    answer+=1
    return answer