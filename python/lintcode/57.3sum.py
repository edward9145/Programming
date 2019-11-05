class Solution:
    """
    @param numbers: Give an array numbers of n integer
    @return: Find all unique triplets in the array which gives the sum of zero.
    """
    def threeSum(self, numbers):
        # write your code here

timeout
        solution = set()
        from itertools import combinations
        for comb in combinations(numbers, 3):
            if sum(comb) == 0:
                solution.add(tuple(sorted(comb)))
        
        output = [list(o) for o in solution]
        return output
            