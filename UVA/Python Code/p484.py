while True:
    try:
        a=str(input())
    except EOFError:
        break
    b=[0]*10000
    for i in range (len(a)):
        if a[i] !=' ':
            b[int(a[i])]=b[int(a[i])]+1
    for i in range(len(a)):
        if a[i] !=' ':
              if b[int(a[i])]!=0:
                 print(a[i],' ',b[int(a[i])])
                 b[int(a[i])]=0
        
