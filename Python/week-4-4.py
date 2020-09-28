int(input())
lst=input().split()
lst=list(map(int,lst))
count=0
def MergeSort(array):
    if len(array)==1:
        return array
    m=int(len(array)/2)
    B=MergeSort(array[:m])
    C=MergeSort(array[m:])
    A=Merge(B,C)
    return A
def Merge(B,C):
    global count
    D=[]
    while (B!=[] and C!=[]):

        b=B[0]
        c=C[0]
        if(b<=c):
            D.append(b)
            B.pop(0)
        else:
            D.append(c)
            C.pop(0)
            count=count+len(B)
    for i in B:
        D.append(i)
    for i in C:
        D.append(i)

    return D
MergeSort(lst)
print(count)
