while True:
    try:
        n=int(input())
        x=int(input())
    except EOFError:
        break
    print(round(x**(1/n)))
