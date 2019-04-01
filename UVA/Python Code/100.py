def sol(i,j):
    c=t=1
    for n in range(i, j+1):
        c=1
        while n!=1:
            if n%2==0:
                n=n//2
            else:
                n=(3*n)+1
            c=c+1
        t=max(t,c)
    return t
while True:
    try:
        a,b=map(int,input().split())
        print(a,b,sol(a,b))
    except EOFError:
        break;
    