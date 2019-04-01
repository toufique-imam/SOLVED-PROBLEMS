#UVA_299_Train Swapping
import sys

while True:
    try:
        test=int(input())
    except EOFError:
        break
    #test=int(input()) sudhu dilei hbe lab e submit er somoy
    while(test):
        n=int(input())
        c=0
        i=1
        m=list(map(int,input().split()))
        while(i<n):
            j=n-1
            while j>=i:
                if m[j-1]>m[j]:
                    c+=1
                    t=m[j-1]
                    m[j-1]=m[j]
                    m[j]=t
                j-=1
            i+=1
        print("Optimal train swapping takes ",c," swaps.",sep="")
        test-=1
