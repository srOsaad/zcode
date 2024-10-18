n = int(input())
n+=1
for l in range(1,n):
    print(int(l*l*(l*l-1)*0.5 - 4*(l-2)*(l-1)))