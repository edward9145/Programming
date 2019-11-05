from collections import deque

class Solution:
    """
    @param grid: a boolean 2D matrix
    @return: an integer
    """
    H, W = 0, 0
    check = []
    
    def numIslands(self, grid):
        # write your code here
        self.H = len(grid)
        if self.H == 0:
            return 0

        self.W = len(grid[0])
        for j in range(self.H):
            self.check.append([0]*self.W)
        island = 0

        self.printArray(grid)
        
        for j in range(self.H):
            for i in range(self.W):
                if grid[j][i] == 1 and self.check[j][i] == 0:
                    queue = deque([(j,i)])
                    print("before: ")
                    self.printArray(grid)

                    self.starSearch(grid, queue)
                    island = island + 1
                    print("after: ")
                    
                    self.printArray(grid)
                    print(island)
                    print('')
                    
        return island
                
    def starSearch(self, grid, queue):
        while len(queue) > 0:
            print(queue)
            self.printArray(grid)
            j,i = queue.popleft()
            if self.check[j][i] == 1:
                continue
            
            self.check[j][i] = 1
            adjacent_pos_list = self.getAdjacentPos(j, i)
            print("adj: ", adjacent_pos_list)
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

    def printArray(self, grid):
        for j in range(self.H):
            print(grid[j], self.check[j])
        print('')
        
        
s = Solution()
s.numIslands([[0,1,0],[1,0,1],[0,1,0]])
s.numIslands([[1]])
# s.numIslands([])
# s.numIslands([[1,1]])
# s.numIslands([[1,1,0,0,0],[0,1,0,0,1],[0,0,0,1,1],[0,0,0,0,0],[0,0,0,0,1]])