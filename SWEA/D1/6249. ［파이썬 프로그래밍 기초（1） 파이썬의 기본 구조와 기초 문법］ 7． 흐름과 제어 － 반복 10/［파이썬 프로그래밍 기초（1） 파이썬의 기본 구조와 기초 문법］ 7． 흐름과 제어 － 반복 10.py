def main():
    n = int(input())
    num_list = []
    while n>0:
        r = n%10
        num_list.append(r)
        n = (n-r)/10
    for i in range(0,10):
        print(i,end = " ")
    print('')
    for i in range(0,10):
        cnt = 0
        for j in range(0,len(num_list)):
            if i == num_list[j]:
                cnt+=1
        print(cnt,end = " ")
main()