n=int(input())
if n==1:
    print("1\n1")
    exit
K=n
sum=[]
for i in range(1,n):
    if K>i*2:
        sum.append(i)
        K=K-i
    else:
        sum.append(K)
        break
print(len(sum))
print(*sum)
