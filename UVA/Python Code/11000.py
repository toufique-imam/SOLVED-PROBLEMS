while 1:
    n=int(input())
    if n==-1:
        break
    else:
        TB=1
        QB=1
        MB=0
        FB=0
        i=0
        while i<n:
            FB=MB
            MB=TB
            TB=FB+MB+1
            i+=1
        print(MB,TB)
