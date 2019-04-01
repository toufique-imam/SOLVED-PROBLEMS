n=str(input())
l=len(n)
m=[' ']*l
for i in range(l):
    m[i]=chr(ord(n[i])-7)
x=''.join(m)
print(x)
#print(*m, sep='')