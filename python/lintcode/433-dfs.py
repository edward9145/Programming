from collections import deque

class Solution:
    """
    @param grid: a boolean 2D matrix
    @return: an integer
    """
    H, W = 0, 0
    check = None
    
    def numIslands(self, grid):
        # write your code here
        self.H = len(grid)
        if self.H == 0:
            return 0

        self.W = len(grid[0])
        self.check = []
        for j in range(self.H):
            self.check.append([0]*self.W)
        island = 0
        
        for j in range(self.H):
            for i in range(self.W):
                if grid[j][i] == 1 and self.check[j][i] == 0:
                    queue = deque([(j,i)])
                    self.starSearch(grid, queue)
                    island = island + 1
                    
        return island
                
    def starSearch(self, grid, queue):
        while len(queue) > 0:
            j,i = queue.popleft()
            if self.check[j][i] == 1:
                continue
            
            self.check[j][i] = 1
            adjacent_pos_list = self.getAdjacentPos(j, i)
            for pos in adjacent_pos_list:
                y, x = pos
                if grid[y][x] == 1 and self.check[y][x] == 0:
                    queue.append((y,x))
        return True
            
    def getAdjacentPos(self,j,i):
        pos_list = []
        if j-1 >= 0: pos_list.append((j-1, i)) 
        if j+1 < self.H: pos_list.append((j+1, i)) 
        if i-1 >= 0: pos_list.append((j, i-1)) 
        if i+1 < self.W: pos_list.append((j, i+1)) 
        return pos_list
