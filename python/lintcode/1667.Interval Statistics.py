http://programmersought.com/article/26991300413/;jsessionid=32A86289FBA9FA7A71431B4759E9832C

# 1667. Interval Statistics
# cat-only-icon
# CAT Only
# 中文English
# Given arr, an array of 01 and an integer k. You need to count how many intervals meet the following conditions:

# Both start and the end of the interval are 0 (allowing the length of the interval to be 1).
# The number of 1 in the interval is not more than k
# Example
# Example 1:

# Input: arr = [0, 0, 1, 0, 1, 1, 0], k = 1
# Output: 7
# Explanation: [0, 0], [1, 1], [3, 3], [6, 6], [0, 1], [0, 3], [1, 3] (The interval [i, j] means the elements between index i(included) and index j(included))
# Example 2:

# Input: arr = [1, 1, 1, 0, 0, 1], k = 2
# Output: 3
# Explanation: [3, 3], [4, 4], [3, 4] (The interval [i, j] means the elements between index i(included) and index j(included))
# Notice
# The length of arr does not exceed 10^5

class Solution:
    """
    @param arr: the 01 array
    @param k: the limit 
    @return: the sum of the interval
    """
    def intervalStatistics(self, arr, k):
        # Write your code here.
        if not arr:
            return 0
        
        # start pointer, end pointer
        # check count1 between start and end
        # O(n^2)
        
        sum = 0
        for i in range(len(arr)):
            if arr[i] == 0:
                count1 = 0
                for j in range(i, len(arr)):
                    if arr[j] == 0:
                        sum += 1
                        # print(i,j)
                    else:
                        count1 += 1
                        
                    if count1 > k:
                        break
        
        return sum
                
        