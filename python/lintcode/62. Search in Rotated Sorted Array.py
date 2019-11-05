# 62. Search in Rotated Sorted Array
# https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
# https://www.jiuzhang.com/solution/search-in-rotated-sorted-array/#tag-highlight-lang-python

class Solution:
    """
    @param A: an integer rotated sorted array
    @param target: an integer to be searched
    @return: an integer
    """
    def search(self, A, target):
        # write your code here
        if not A:
            return -1
        
        low, high = 0, len(A)-1
        while low+1 < high:
            mid = (low+high)//2
            if target == A[mid]:
                return mid
                
            elif A[mid] >= A[low]:  # [sorted...mid...rotated_pivot...]
                if A[low] <= target < A[mid]:
                    high = mid
                else:
                    low = mid
            else:                   # [...rotated_pivot...mid...sorted]
                if A[mid] < target <= A[high]:
                    low = mid
                else:
                    high = mid
                    
        if A[low] == target:
            return low
        if A[high] == target:
            return high
        return -1

s = Solution()
result = s.search([5,1,2,3,4], 3)
print(result)
