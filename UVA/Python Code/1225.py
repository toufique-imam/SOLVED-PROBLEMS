import sys
test=int(input())
while test:
    a=[0]*10
    n=int(input())
    i=1
    while i<=n:
        temp=i
        while temp:
            j=temp%10
            a[j]+=1
            temp=temp//10
        i+=1
    print(a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9])
    test-=1
