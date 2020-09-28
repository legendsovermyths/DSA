i=int(input())
sum=0
lst1=list(map(int,input().split()));lst1.sort()
lst2=list(map(int,input().split()));lst2.sort()
for i in range(i):
    sum=sum+lst1[i]*lst2[i]
print(sum)
