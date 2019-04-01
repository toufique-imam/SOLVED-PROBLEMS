import sys

#sys.stdin=open("input.txt","r")
#sys.stdout=open("output.txt","w")

while True:
    try:
        b1,g1,c1,b2,g2,c2,b3,g3,c3=map(int,input().split())
    except EOFError:
        break
    m=10**9
    temp=c1+g1+b2+g2+b3+c3
    if temp<m:
        m=temp
        a=1

    temp=c1+g1+b2+c2+b3+g3
    if temp<m:
        m=temp
        a=2

    temp=b1+g1+c2+g2+b3+c3
    if temp<m:
        m=temp
        a=3

    temp=b1+g1+b2+c2+c3+g3
    if temp<m:
        m=temp
        a=4

    temp=c1+b1+c2+g2+b3+g3
    if temp<m:
        m=temp
        a=5

    temp=c1+b1+b2+g2+g3+c3
    if temp<m:
        m=temp
        a=6

    if a==1:
       print("BCG",m)
    elif a==2:
        print("BGC",m)
    elif a==3:
        print("CBG",m)
    elif a==4:
        print("CGB",m)
    elif a==5:
        print("GBC",m)
    elif a==6:
        print("GCB",m)
