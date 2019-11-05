Failed
"""
https://www.jiuzhang.com/solution/reach-a-number/#tag-highlight-lang-python

797. Reach a Number
中文English
You are standing at position 0 on an infinite number line. There is a goal at position target.

On each move, you can either go left or right. During the n-th move (starting from 1), you take n steps.

Return the minimum number of steps required to reach the destination.

Example
Example1

Input: target = 3
Output: 2
Explanation:
On the first move we step from 0 to 1.
On the second step we step from 1 to 3.
Example2

Input: target = 2
Output: 3
Explanation:
On the first move we step from 0 to 1.
On the second move we step  from 1 to -1.
On the third move we step from -1 to 2.
Notice
target will be a non-zero integer in the range [-10^9, 10^9].
"""



class Solution:
    """
    @param target: the destination
    @return: the minimum number of steps
    """
    def reachNumber(self, target):
        # Write your code here
        if target == 0:
            return 0

        target = abs(target)
        position = 0
        step = 1

        # target = 2
        # step = 1
        # pos + step = 1, 1<2
        # pos = 1, step = 2
        # pos + step = 3, 3<2 -> false
        # 
        # gap = 2 - 1 = 1, move 

        while (position + step) <= target:
            position += step
            step += 1
        
        if position == target:
            return step
        
        gap = target - position
        return (step-1) + gap * 2

s = Solution()
res = s.reachNumber(10)
print(res)
