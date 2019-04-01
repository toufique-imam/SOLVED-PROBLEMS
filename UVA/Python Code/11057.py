while 1:
    n=input()
    if(n=='End Of File'):
        break
    else:
        z=int(n)
    f=0
    m=100000
    a=list(map(int,input().split()))
    b=int(input())
    for i in range (z-1):
        for j in range(i,z):
            if(a[i]+a[j]==b):
                if m>abs(a[i]-a[j]):
                    x=a[i]
                    y=a[j]
                    m=abs(a[i]-a[j])
    message = 'Peter should buy books whose prices are {} and {}.'
    print(message.format(x,y))