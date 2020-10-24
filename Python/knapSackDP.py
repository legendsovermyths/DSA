def knapSack(n,m,arr):
    list = [[0 for x in range(n + 1)] for x in range(m + 1)] 
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if j >= arr[i - 1]:
                list[i][j] = max(list[i - 1][j], list[i - 1][j - arr[i - 1]] + arr[i - 1])
            else:
                list[i][j] = list[i - 1][j]
    return list[m][n]
m, n = input().split()
m, n = int(m), int(n)
arr = list(map(int, input().split()))
print(knapSack(m,n,arr))