sorted=input().split()
keys=input().split()
sorted.pop(0)
keys.pop(0)
sorted=list(map(int,sorted))
keys=list(map(int,keys))
def binarySearch(A,low,high,key):
    if high<low:
        print("-1",end=" ")
        return
    mid=int(low+(high-low)/2)
    if key==A[mid]:
        print(mid,end=" ")
        return
    elif key<A[mid]:
        binarySearch(A,low,mid-1,key)
    else:
        binarySearch(A,mid+1,high,key)
for key in keys:
    binarySearch(sorted,0,len(sorted)-1,key)
