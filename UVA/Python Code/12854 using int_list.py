import sys
while True:
    try:
        n=list(map(int,input().split()))
        m=list(map(int,input().split()))
    except EOFError:
        break

    f=1
    for i in range(5):
        if f==0:
            break
        elif n[i]==m[i]:
            f=0

    if f==0:
        print('N')
    else:
        print('Y')