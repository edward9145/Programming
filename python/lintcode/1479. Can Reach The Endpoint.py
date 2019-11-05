"""
1479. Can Reach The Endpoint
中文English
Given a map size of m*n, 1 means space, 0 means obstacle, 9 means the endpoint. You start at (0,0) and return whether you can reach the endpoint.

Example
Example1

Input: 
[
	[1,1,1],
	[1,1,1],
	[1,1,9]
]
Output: true
Example2

Input: 
[
	[1,1,1],
	[1,0,0],
	[1,0,9]
]
Output: false
"""


class Solution:
    """
    @param map: the map
    @return: can you reach the endpoint
    """
    def reachEndpoint(self, map):
        # Write your code here
        if not map or len(map[0]) == 0:
            return False
        m = len(map)
        n = len(map[0])
        
        visited = [[False]*n for i in range(m)]
        queue = [(0,0)]
        while len(queue) > 0:
            node = queue.pop(0)
            row, col = node
            visited[row][col] = True
            if map[row][col] == 9:
                return True
            dx = [0,1]
            dy = [1,0]
            for i in range(2):
                next_row = row + dy[i]
                next_col = col + dx[i]
                if self.isValid(map, m, n, next_row, next_col) \
                    and not visited[next_row][next_col]:
                    queue.append((next_row, next_col))
        
        return False
        
        
    def isValid(self, map, m, n, row, col):
        if row < m and col < n:
            if map[row][col] == 1 or map[row][col] == 9:
                return True
        return False

s = Solution()
result = s.reachEndpoint([
    [1,1,1],
    [1,1,0],
    [1,0,9]
])
print(result)
