while 1:
    side1,side2,side3=map(int,input().split())
    if(side1==0 and side2==0 and side3==0):
        break
    elif(side1 * side1 + side2 * side2 == side3 * side3  or side1 * side1 + side3 * side3 == side2 * side2  or side3 * side3 + side2 * side2 == side1 * side1):
        print('right')
    else:
        print('wrong')
