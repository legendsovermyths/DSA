n = int(input())
lst = []

for _ in range(n):
    num1, num2 = [int(i) for i in input().split()]
    lst.append((num1,num2))

lst.sort(key = lambda x: x[1])

index = 0
coordinates = []

while index < n:
    curr = lst[index]
    while index < n-1 and curr[1]>=lst[index+1][0]:
        index += 1
    coordinates.append(curr[1])
    index += 1
print(len(coordinates))
print(' '.join([str(i) for i in coordinates]))
