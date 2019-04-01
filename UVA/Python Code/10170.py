import sys

while True:
    s, d = map(int, input().split())
    summ=0
    i=s
    while 1:
        summ=summ+i
        if(summ>=d):
            print(i)
            break
        i+=1
