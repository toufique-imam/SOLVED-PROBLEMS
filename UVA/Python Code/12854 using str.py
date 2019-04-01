n=str(input())
m=str(input())
f=1
for i in range(5):
    if f:
        if n[i]=='0':
            if m[i]!='1':
                f=0
                #print(n[i],m[i])
        elif n[i]=='1':
            if m[i]!='0':
                f=0
                #print(n[i], m[i],i)
if f==0:
    print('N')
else:
    print('Y')