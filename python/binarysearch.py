# https://www.geeksforgeeks.org/binary-search/

class Solution:
    """
    @param A: an integer sorted array
    @param target: an integer to be inserted
    @return: An integer
    """
    def searchInsert(self, A, target):
        # write your code here
        if not A or len(A) == 0:
            return 0
        mid = self.binarySearch(A, 0, len(A)-1, target)
        print(mid)
        return mid
        
    def binarySearch(self, A, low, high, target):
        while low <= high:
            mid = (low + high)//2
            if target < A[mid]:
                high = mid-1
            elif target > A[mid]:
                low = mid+1
            elif target == A[mid]:
                break 

        if target > A[mid]:
            mid = mid+1
        return mid

s = Solution()
s.searchInsert([1,3,5,6], 3)
