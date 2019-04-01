import sys

#sys.stdin=open("input.txt","r")
#sys.stdout=open("output.txt","w")

while True:
    try:
        n = str(input())
    except EOFError:
        break
    l=len(n)
    b = -1
    x=[]
    for i in range(l):
        if n[i] == ' ':
            j = i - 1
            while j > b:
                x.append(n[j])
                j -= 1
            x.append(n[i])
            b = i
    i = l - 1
    while i>b:
        x.append(n[i])
        i-=1

    print(''.join(x))
