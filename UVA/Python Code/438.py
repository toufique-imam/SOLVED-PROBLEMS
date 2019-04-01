#UVA_438_The Circumference of the Circle
import sys
#sys.stdin=open("input.txt")

def eq_len(x1,y1,x2,y2):
    return ((x1-x2)**2+(y1-y2)**2)**0.5
#add this try>except condition to be accepted in UVA no need to write this in lab :p
while True:
    try:
        x1,y1,x2,y2,x3,y3=map(float,input().split())
    except EOFError:
        break
    a=eq_len(x1,y1,x2,y2)
    b=eq_len(x2,y2,x3,y3)
    c=eq_len(x3,y3,x1,y1)

    s=0.5*abs(x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1)
    print(round((a*b*c*2*3.141592653589793/(4*s)),2))
