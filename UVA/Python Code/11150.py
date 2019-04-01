while 1:
    n=int(input())
    if n==0:
        break
    else:
        s=n
        while n>=3:
            s+=n//3
            n=(n//3)+(n%3)
        if n==2:
            s+=1
        print(s)
        map()
