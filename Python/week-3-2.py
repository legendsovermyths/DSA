n,W=input().split()
n,W=int(n),int(W)
lst=[]
m=[0 for i in range(n)]
k=[0 for i in range(n)]
for i in range(0,n):
    m[i],k[i]=input().split()
    m[i],k[i]=int(m[i]),int(k[i])
    lst.append(m[i]/k[i])
def func(m,k,lst,W,n):
    maxi=0

    for i in range(n):
        if W==0:
            return maxi
        ind=lst.index(max(lst))
        if k[ind]==0:
             lst[ind]=0
             ind=lst.index(max(lst))
        a=min(k[ind],W)
        maxi=maxi+a*lst[ind]
        k[ind]=k[ind]-a
        W=W-a
    return maxi

print("{0:.4f}".format(func(m,k,lst,W,n)))
