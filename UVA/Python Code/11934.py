import sys
def equ_val(a,b,c,x):
    f=a*(x**2)+b*x+c
    return f
while 1:
    a,b,c,d,l=map(int,input().split())
    if a==0 and b==0 and c==0 and d==0 and l==0 :
        break
    else:
        t=0
        for i in range(l+1):
            q=equ_val(a,b,c,i)
            if q%d==0:
                t+=1
        print(t)
