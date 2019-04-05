while True:
    try:
        cof = input().split()
        x = input().split()
        for i in range(len(cof)):
            cof[i] = int(cof[i])
        for i in range(len(x)):
            x[i] = int(x[i])
        l = len(cof)
        c = ' '
        for i in range(len(x)):
            if(i+1 == len(x)):
                c = '\n'
            sum = 0
            j = l-1
            now = x[i]
            nn = 1
            while(j > -1):
                sum = (sum+cof[j]*nn)
                nn *= now
                j = j-1
            print(sum, end=c)
    except EOFError:
        break
