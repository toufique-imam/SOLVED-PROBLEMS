import sys
#sys.stdin=open("input.txt")
def sol(n):
    c=0
    t=1
    while n!=1:
        if n%2==0:
            n=n//2
        else:
            n=(3*n)+1
        c=c+1
    return max(c,t)
while True:
    try:
        x,y=map(int,input().split())
    except EOFError:
        break
    #lab e submit er somoy x,y=map(int,input().split()) dilei hbe

    if x==0 and y==0:
        break
    else:
        a=min(x,y)
        b=max(x,y)
        temp=a
        m=0
        p=0
        d=0
        if a==1 and (b==1 or b==2):
            m=3
            p=1
            print("Between ", a, " and ", b, ", ", p, " generates the longest sequence of ", m, " values.", sep="")
        else:
            while temp<=b:
                d=sol(temp)
                if(m<d):
                    m=d
                    p=temp
                temp+=1
            print("Between ",a," and ",b,", ",p," generates the longest sequence of ",m," values.",sep="")

##eta UVA te TLE khaise :p worst case e 3.1sec output time lage maybe
