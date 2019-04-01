import sys
def digit_slicer(temp):
    b=[]
    while temp:
        x=temp%10
        b.append(x)
        temp//=10
    b.reverse()
    return b
    
while 1:
    n=int(input())
    if n==0:
        quit()
        
    a=digit_slicer(n)
    q=len(a)
    y=a[0]*(10**(q-1))
    z=(a[0]+1)*(10**(q-1))
    p=[]
    i=y
    for i in range(y,z+1):
        c=digit_slicer(i)
        e=q-1
        s=0
        while e>=0:
            k=10**(q-2)
            for g in range(q):
                if(g!=e):
                    s=s+c[g]*k
                    k=k//10
            e=e-1
            if i-s==n:
                p.append(i)
        i=i+1
    print(p)
    

    
    

    
