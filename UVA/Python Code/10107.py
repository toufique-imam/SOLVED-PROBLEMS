import sys
#sys.stdin=open("input.txt","r")
#sys.stdout=open("output.txt","w")
i=1
a=[]
while True:
    try:
        n=int(input())
        a.append(n)
    except EOFError:
        break
    a.sort()
    if i==1:
        print(a[0])
    elif i%2==0:
        print((a[(i-1) // 2] + a[(i-1) // 2 + 1]) // 2)
    elif i%2!=0:
        print(a[(i-1) // 2])
    i+=1
