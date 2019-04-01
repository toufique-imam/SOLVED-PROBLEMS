#UVA_444
import sys

def ulta(x):
    if x>99:
        return (x%10)*100+((x//10)%10)*10+(x//100)
    elif x//10==0:
        return x*100
    elif x==11 or x==12 or x==10:
        return x*10
    else:
        return (x%10)*10+x//10
def bhango(x):
    temp=x
    q=[]
    while(temp!=0):
        f=ulta(temp%100)
        if(f<32):
            q.append(ulta(temp%1000))
            temp//=1000
        else:
            q.append(f)
            temp//=100
    return q


while True:
    try:
        s=input()
    except EOFError:
        break
    #write only s=str(input()) while submitting in lab
    try:
        x=int(s)
        z=bhango(x)
        #print(z)
        ans=[]
        for i in range(len(z)):
            ans.append(chr(z[i]))

        print(*ans,sep='')



    except ValueError:
        l=len(s)-1
        a=[]
        while l>=0:
            x=ord(s[l])
            if x%10==0:
                a.append(0)
            d=ulta(x)
            a.append(d)
            l-=1
        print(*a,sep='')
