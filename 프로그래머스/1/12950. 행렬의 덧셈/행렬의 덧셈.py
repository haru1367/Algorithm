def solution(arr1,arr2):
    answer = []
    for i in range(0,len(arr1)):
        result = []
        for j in range(0,len(arr1[0])):
            k = arr1[i][j] + arr2[i][j]
            result.append(k)
        answer.append(result)
    return answer