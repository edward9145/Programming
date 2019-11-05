# 1751. Cowherd&Weaver
# cat-only-icon
# CAT Only
# 中文English
# On the Qixi Festival, the Cowherd and the Weaver play together in a maze size of n*m . However, they get separated from each other. Now given the maze consisting of .,*,S,T, where . denotes an empty space, * denotes an obstacle, S denotes the position of the cowherd, T denotes the position of the weaver, the Cowherd and the Weaver will try to find each other(they can move to the grid up or down or left or right or stand still, but they can't walk outside of the maze or move to obstacles).Is it possible for them reunion? If possible, return True, otherwise return False.

# Example
# Example 1:

# Input: 
# [
# "S..*",
# "*.**",
# "...T"
# ]
# Output: true
# Explanation:
# weaver don't need to move
# Cowherd's route:(0,0)->(0,1)->(1,1)->(2,1)->(2,2)->(2,3)
# Example 2:

# Input:
# [
# "S..*",
# "***.",
# "...T"
# ]
# Output: false
# Explanation
# It is impossible for them to reunion
# Notice
# 2<=n,m<=1000

class Solution:
    """
    @param maze: the maze 
    @return: Can they reunion?
    """
    N, M = 0, 0
    visited = set()
    MAZE = None
    def findHer(self, maze):
        # Write your code here
        self.N = len(maze)
        self.M = len(maze[0])
        self.MAZE = [list(maze[i]) for i in range(self.N)]
        print(self.MAZE)
        self.visited = set()
        
        s_pos = (0,0)
        t_pos = (0,0)
        for row in range(self.N):
            for col in range(self.M):
                if maze[row][col] == 'S':
                    s_pos = (row, col)
                if maze[row][col] == 'T':
                    t_pos = (row, col)
        can = self.dfs(maze, s_pos, t_pos)
        print(can)
        
        for r in self.MAZE:
            print("".join(r))
        return can
        
    def is_valid(self, x, y):
        return 0<= x <self.M and 0<=y < self.N

    def dfs(self, maze, pos, target):
        found = False
        dx = [-1, 0, 1, 0]
        dy = [0, -1, 0, 1]
        y, x = pos
        next_pos_list = [(y+dy[i],x+dx[i]) for i in range(4)]
        
        if pos == target:
            return True
        self.visited.add(pos)
        print(pos)
        self.MAZE[y][x] = 'o'
        for next_pos in next_pos_list:
            next_y, next_x = next_pos
            if self.is_valid(next_x, next_y) \
            and maze[next_y][next_x] != '*' \
            and next_pos not in self.visited:
                found = self.dfs(maze, next_pos, target)
            if found:
                break
        
        return found

s = Solution()
s.findHer(
[
".........T...*",
"**.*..........",
"........**....",
"S*.**........."
]
)
