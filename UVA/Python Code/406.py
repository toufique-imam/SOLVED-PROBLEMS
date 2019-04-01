#UVA_406
#USING_SEIVE_TECHNIQUE

#eta normally root technique diayo kora jabe karon input range 10000
#input range besi hoile 10^9 hole seive use kora must :)

#seive_begin
isPrime=[1]*10000005
isPrime[0]=0
prime=[]
n=10000001
for i in range(4,n,2):
    isPrime[i]=0
i=3
while i**2<=n:
    if isPrime[i]==1:
        j=i**2
        while j<=n:
            isPrime[j]=0
            j+=2*i
    i+=2
for i in range(1,n):
    if isPrime[i]==1:
        prime.append(i)

#seive_ends
#now we have all primes stored in prime array upto 10^8


while True:
    try:
        a,b=map(int,input().split())
    except EOFError:
        break
    #just a,b=map(int,input().split()) dilei hbe__lab e submit er time e
    x=0
    temp2=b
    temp1=a
    fs=[]

    for i in range (len(prime)):
        if(prime[i]<=a):
            fs.append(prime[i])
            x+=1
        else:
            break

    if(x%2==1):
        b=b*2-1
    else:
        b=b*2
    if(b>x):
        b=x
    #print(b)
    i=x//2-b//2
    j=0
    ans=[]
    while(j<b):
        ans.append(fs[i])
        i+=1
        j+=1
    print("%d %d:"%(temp1,temp2),*ans,sep=' ')
    print()
