#nessY__uva11044

def sol(x,y):
    return (x//3)*(m//3)

t=int(input())
for i in range(t):
    n,m=map(int,input().split())
    print(sol(n,m))
