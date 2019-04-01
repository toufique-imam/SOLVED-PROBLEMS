import sys
while 1:
    n=int(input())
    m=1
    f=1
    a=[]
    for i in range (n):
        x=int(input())
        a.append(x)
    if a[0]<1:
        f=0
    if f:
        for i in range(n-1):
            if a[i]>=a[i+1]:
                f=0
    if f:
        k=0
        r=[]
        for i in range(n):
            for j in range(i,n):
                r.append(a[i]+a[j])
                k+=1
        #print(k)
        for i in range(k):
            if f==0:
                break
            else:
                for j in range(i+1,k):
                    if r[i]==r[j]:
                        f=0
                        break
            
    if f==0:
        print("Case #",m,": It is not a B2-Sequence.")
        print()
        m+=1
    else:
        print("Case #",m,": It is a B2-Sequence.")
        print()
        m+=1
