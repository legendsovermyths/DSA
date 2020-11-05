def CatalanNumber(n):
    dpVec = [0 for i in range(n + 1)]
    dpVec[0] = 1
    for i in range(1, n + 1):
        for j in range(0, i):
            dpVec[i] += dpVec[i - 1 - j] * dpVec[j]
    return dpVec[n]


test = int(input())
for i in range(test):
    print(CatalanNumber(int(input())))
