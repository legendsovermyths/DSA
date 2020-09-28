n=int(input())
lst=input().split()

lst.sort()
count=1;maxcount=0
for i in range(len(lst)-1):


    if lst[i]==lst[i+1]:
        count=count+1
    if count>maxcount:
        maxcount=count

    if lst[i]!=lst[i+1]:
        count=1
if maxcount>len(lst)/2:
    print(1)
else:
    print(0)
