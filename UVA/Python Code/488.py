import sys
#sys.stdin=open("input.txt","r")
#sys.stdout=open("output.txt","w")
while True:
    try:
        test=int(input())
    except EOFError:
        break
    while(test):
        x=input()
        b=int(input())
        c=int(input())
        for s in range(c):
            i=1
            while i<=b:
                print(str(i)*i)
                i+=1

            i=i-2
            while i>=1:
                print(str(i)*i)
                i-=1

            if s!=c-1:
                print()
        test -= 1
        if test:
            print()

