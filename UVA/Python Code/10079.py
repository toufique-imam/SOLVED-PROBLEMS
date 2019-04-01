import sys

#sys.stdin=open("input.txt","r")
#sys.stdout=open("output.txt","w")
while True:
    try:
        n=int(input())
    except EOFError:
        break
    if n<0:
        break
    else:
        s=n*(n+1)//2
        print(s+1)