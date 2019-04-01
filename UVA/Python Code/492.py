def is_vowel(c):
    if c == 'a' or c == 'A' or c == 'e' or c == 'E' or c == 'i' or c == 'I' or c == 'o' or c == 'O' or c == 'u' or c == 'U':
        return 1


n = str(input())
a = []
b = [0]
c = []
for i in range(len(n)):
    a.append(n[i])
    if n[i] == ' ':
        b.append(i+1)#space kothay seta r info

for i in range(len(b)):
    if is_vowel(a[b[i]]):
        j = b[i]
        while j<len(a):
            if a[j]==' ':
                break
            c.append(a[j])
            j += 1
        c.append('a')
        c.append('y')
        c.append(' ')
    else:
        t = a[b[i]]
        j=b[i]+1
        while j < len(a):
            if a[j]==' ':
                break
            c.append(a[j])
            j += 1
        c.append(t)
        c.append('a')
        c.append('y')
        c.append(' ')
print(*c, sep='')
        
    
