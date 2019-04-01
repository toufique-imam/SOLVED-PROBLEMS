import sys
sys.stdin=open('input.txt','r')
sys.stdout=open('output.txt','w')
while True:
    try:
        test=int(input())
    except EOFError:
        break
    while test:
        x=list(map(int,input().split()))
        n=x[0]
        x.remove(x[0])
        x.sort()
        mid=(x[len(x)//2])

        s=0
        for i in range(n):
            s+=abs(mid-x[i])
        print(s)
        test-=1