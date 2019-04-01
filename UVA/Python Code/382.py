n=list(map(int,input().split()))
print('PERFECTION OUTPUT')

j=0
while n[j]:
    s=0
    for i in range (1,n[j]):
        if n[j]%i==0:
            s+=i
    if s>n[j]:
        t=' ABUNDANT'
    if s<n[j]:
        t=' DEFICIENT'
    if s==n[j]:
        t=' PERFECT'
    if n[j]<10:
        print('   ',n[j],t)
    elif n[j]<100:
        print('  ',n[j],t)
    elif n[j]<1000:
        print(' ',n[j],t)
    else:
        print(n[j],t)
    j+=1
print('END OF OUTPUT')