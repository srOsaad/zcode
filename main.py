n = int(input())
while n!=1 :
    print(n,end=' ')
    if n & 1:  #this line checks if n's last bit is 1 or not as only odd number has 1 as their last bit.
        n=n*3+1
    else :
        n>>=1
print(1)