x = int(input())
ans = 0

def dn(m) :
    r = 0
    x = int(m**0.5)
    x+=1
    for n in range(1,x) :
        if m%n == 0 :
            r+=1
            if n != m/n : 
                r+=1
    return r

x+=1
for l in range(1,x) :
    ans += dn(l) * l
    print(ans)
print(ans,end='')