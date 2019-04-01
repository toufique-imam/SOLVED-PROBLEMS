while 1:
    n=int(input())
    if n==0:
        break
    x=(n*10)//9;
    if n%9==0:
        print(x-1,x)
    else:
         print(x)
