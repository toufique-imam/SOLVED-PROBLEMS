import sys
c=int(input())
for i in range(c):
    x=int(input())
    temp=x
    s=0
    c=0
    l=[]
    while temp:
        y=int(input())
        s=s+y
        l.append(y)
        temp-=1
    s=s/x
    for j in range(x):
        if l[j]>s:
            c+=1
    print(c*100/x,"%")
        
        
        
