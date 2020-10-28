def isValid(vact, i, j, vis):
    rows = len(vact)
    cols = len(vact[0])
    return (
        i < rows
        and j < cols
        and not vis[i][j]
        and vact[i][j] == 1
        and i >= 0
        and j >= 0
    )


def shortestPath(vact, i, j, x, y, vis):
    if not isValid(vact, i, j, vis):
        return 9999
    if i == x and j == y:
        return 0
    vis[i][j] = 1
    left = shortestPath(vact, i, j - 1, x, y, vis) + 1
    right = shortestPath(vact, i, j + 1, x, y, vis) + 1
    up = shortestPath(vact, i - 1, j, x, y, vis) + 1
    bottom = shortestPath(vact, i + 1, j, x, y, vis) + 1
    vis[i][j] = 0
    return min(left, right, up, bottom)


vact = [[1, 0, 0, 0], [1, 1, 0, 1], [0, 1, 1, 1]]
vis = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]
print(shortestPath(vact, 0, 0, 2, 3, vis))
