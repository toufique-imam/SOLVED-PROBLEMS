n=int(input())
while n:
    s,d=map(int,input().split())
    if s>d:
        print('>')
    elif s<d:
        print('<')
    else:
        print('=')
    n-=1
