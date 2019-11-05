def getPath(grid):
    if not grid or len(grid) == 0:
        return []

    R = len(grid)
    C = len(grid[0])
    path = []
    memo = [[False]*C for i in range(R)]  # memorization
    
    calcPath(grid, R-1, C-1, path, memo)
    return path

def calcPath(grid, row, col, path, memo):
    if memo[row][col]:
        return True
    
    if row<0 or col<0 or grid[row][col] == 0:
        return False

    ## is at origin
    isOrigin = (row==0 and col ==0)
    if isOrigin or calcPath(grid, row-1, col, path, memo) or calcPath(grid, row, col-1, path, memo):
        path.append((row,col))
        memo[row][col] = True
    return True

def getPath_no_recursive(grid):
    if not grid or len(grid) == 0:
        return []

    R = len(grid)
    C = len(grid[0])
    path = []
    memo = [[False]*C for i in range(R)]  # memorization
    
    calcPath_no_recursive(grid, R-1, C-1, path, memo)
    return path

def calcPath_no_recursive(grid, row, col, path, memo):
    ## is at origin
    stack = []
    stack.append((row, col))
    while len(stack):
        node = stack.pop()
        row, col = node
        if row<0 or col<0 or grid[row][col] == 0:
            continue
        if memo[row][col]:
            continue
        if grid[row][col]:
            memo[row][col] = True
            path.insert(0, (row, col))
        if row==0 and col==0:
            break
        stack.append((row-1,col))
        stack.append((row,col-1))
    return memo[0][0]

g = [
[1,1,1],
[0,1,0],
[0,1,1]]
p = getPath(g)
print(p)

p2 = getPath_no_recursive(g)
print(p2)

