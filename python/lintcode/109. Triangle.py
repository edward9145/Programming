
class Solution:
    """
    @param triangle: a list of lists of integers
    @return: An integer, minimum path sum
    """
    def minimumTotal(self, triangle):
        # write your code here
        if not triangle or len(triangle) == 0 or len(triangle[0]) == 0:
            return 0
        """
        2           2
        3,4         5,6
        6,5,7       11,min(5,6)+5=5+5=10,11
        4,1,8,3     15,min(11,10)+1=11,....
        
        sum[row][i] = min(sum[row-1][i], sum[row-1][i-1]) + triangle[row][i]
        """
        
        path_sum = [triangle[0]]
        for row in range(1, len(triangle)):
            row_sum = []
            row_len = len(triangle[row])
            for i in range(row_len):
                if i == 0:
                    min_path = triangle[row][i] + path_sum[row-1][0]
                elif i == row_len - 1:
                    min_path = triangle[row][i] + path_sum[row-1][i-1]
                else:
                    min_path = triangle[row][i] + min(path_sum[row-1][i], path_sum[row-1][i-1])
                row_sum.append(min_path)
            path_sum.append(row_sum)
        
        bottom_path = path_sum[-1]
        min_path_sum = min(bottom_path)
        return min_path_sum

s = Solution()
o = s.minimumTotal(
    [
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
)
print(o)
