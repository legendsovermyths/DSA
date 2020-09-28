def isgreater(digit,maxDigit):
    digit,maxDigit=str(digit),str(maxDigit)
    return int(digit+maxDigit)>=int(maxDigit+digit)

n=int(input())
lst=input().split()
lst=list(map(int,lst))
answer=""
while lst != []:
    maxDigit=0
    for i in lst:
        if isgreater(i,maxDigit):
            maxDigit=i
    answer=answer+str(maxDigit)
    lst.remove(maxDigit)
print(answer)
