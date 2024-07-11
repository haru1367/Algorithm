def solution(s):
    arr = s.split(' ')
    min_number = int(arr[0])
    max_number = int(arr[0])
    for i in range(0,len(arr)):
        min_number = min(int(arr[i]),min_number)
        max_number = max(int(arr[i]),max_number)
    answer = f'{min_number} {max_number}'
    return answer