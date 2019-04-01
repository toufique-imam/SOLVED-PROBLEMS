mirrorL=['A','E','H','I','J','L','M','O','S','T','U','V','W','X','Y','Z','1','2','3','5','8']
mirrorC=['A','3','H','I','L','j','M','O','2','T','U','V','W','X','Y','Z','1','S','E','Z','8']

while 1:
    a=str(input())
    if a=='':
        break
    else:
        l=len(a)
        l1=len(mirrorL)
        m=0
        p=1
        j=l-1
        for i in range(l//2):
            if p==0:
                break
            else:
                if a[i]!=a[j]:
                    p=0
            j-=1
        j=l-1
        for i in range(l//2):
            for k in range(l1):
                if a[i]==mirrorL[k]:
                    if a[j]==mirrorC[k]:
                        m+=1
            j-=1
    #print(m,l//2)
        if m!=l//2 and p==0:
            print(a,'-- is not a palindrome.')
        elif m==l//2 and p==0:
            print(a,'-- is a mirrored string.')
        elif m!=l//2 and p==1:
            print(a,'-- is a regular palindrome.')
        elif m==l//2 and p==1:
            print(a,'-- is a mirrored palindrome.')
