import sys
c=0
while True:
    try:
        s=str(input())
    except EOFError:
        break
    l=len(s)
    a=[]
    for i in range(l):
        if(s[i]=='"'):
            c+=1
            if c%2==1:
                a.append("``")
            else:
                a.append("''")
        else:
            a.append(s[i])
    print(''.join(a))
