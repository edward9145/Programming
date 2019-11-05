import pprint

class UnionSet:
    
    def __init__(self, H, W):
        self.root = {}
        self.H = H
        self.W = W
    
    def is_boundary(self, key, H, W):
        row, col = key
        return row==0 or row==H-1 or col==0 or col==W-1

    def count_without_boundary(self):
        # pprint.pprint(self.root)
        s = set()
        s_boundary = set()
        for key in self.root:
            r = self.findRoot(key)
            s.add(r)
            if self.is_boundary(key, self.H, self.W): # check boundary
                s_boundary.add(r)
                
        print(s_boundary)
        print(s)
        s = s.difference(s_boundary)
        # print(s)
        return len(s)

    def count(self):
        # pprint.pprint(self.root)
        s = set()
        for key in self.root:
            r = self.findRoot(key)
            s.add(r)
        # print(s)
        return len(s)
    
    def makeSet(self, node):
        self.root[node] = node
    
    def findRoot(self, x):
        # if x not in self.root:
        #     return None
        while(x != self.root[x]):
            x = self.root[x]
        return x
            
    # x <- y
    def union(self, x, y):
        # print("x: %s <- y: %s" % (str(x), str(y)))
        rootX = self.findRoot(x)
        rootY = self.findRoot(y)
        # print("rootX: %s <- rootY: %s" % (str(rootX), str(rootY)))
        self.root[rootY] = rootX
    
class Solution:
    """
    @param grid: a boolean 2D matrix
    @return: an integer
    """
    
    def numIslands(self, grid):
        # write your code here
        if not grid or len(grid) == 0 or len(grid[0]) == 0:
            return 0
        
        H = len(grid)
        W = len(grid[0])
        unionset = UnionSet(H, W)
        
        # traverse all nodes
        #     if node is island
        #         makeset(node)
                # if left_node is island
                #     union(left_node, node)
                # if top_node is island
                #     union(top_node, node)
        # return unionset.count
        
        for row in range(H):
            for col in range(W):
                node = (row, col)
                if grid[row][col] == 1:
                    unionset.makeSet(node)
                    if 0<= col-1 and grid[row][col-1] == 1:
                        left_node = (row, col-1)
                        unionset.union(left_node, node)
                    if 0<= row-1 and grid[row-1][col] == 1:
                        top_node = (row-1, col)
                        unionset.union(top_node, node)

        islands = unionset.count_without_boundary()
        print(islands)
        return islands
                
    
s = Solution()
s.numIslands([[0,1,0],[1,0,1],[0,1,0]])
s.numIslands([[1]])
s.numIslands([])
s.numIslands([[1,1]])
s.numIslands([[1,1,0,0,0],[0,1,0,0,1],[0,0,0,1,1],[0,0,0,0,0],[0,0,0,0,1]])
s.numIslands([[0,0,0,0,0],[0,1,0,0,1],[0,0,0,1,1],[0,0,0,0,0],[0,0,0,0,1]])
