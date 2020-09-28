lst=[0]
f=int(input())
L=int(input())
n=int(input())
lst2=input().split()
for i in lst2:
    lst.append(int(i))

lst.append(f)

length=len(lst)
length=length-2

def minRefills(lst,length,L):
    numRefills=0
    lastRefiil=0;currRefill=0
    while currRefill<=length:
        lastRefiil=currRefill

        while (currRefill<=length and lst[currRefill+1]-lst[lastRefiil]<=L):

            currRefill=currRefill+1
        if(lastRefiil==currRefill):
            return (-1)
        if(currRefill<=n):
            numRefills=numRefills+1
    return numRefills
print(minRefills(lst,length,L))
