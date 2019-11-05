"""
https://www.jiuzhang.com/solution/binary-tree-level-order-traversal/

69. Binary Tree Level Order Traversal
中文English
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

Example
Example 1:

Input：{1,2,3}
Output：[[1],[2,3]]
Explanation：
  1
 / \
2   3
it will be serialized {1,2,3}
level order traversal
Example 2:

Input：{1,#,2,3}
Output：[[1],[2],[3]]
Explanation：
1
 \
  2
 /
3
it will be serialized {1,#,2,3}
level order traversal
Challenge
Challenge 1: Using only 1 queue to implement it.

Challenge 2: Use BFS algorithm to do it.

Notice
The first data is the root node, followed by the value of the left and right son nodes, and "#" indicates that there is no child node.
The number of nodes does not exceed 20.
"""

"""
Definition of TreeNode:
"""
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None


class Solution:
    """
    @param root: A Tree
    @return: Level order a list of lists of integer
    """
    def levelOrder(self, root):
        # write your code here
        
        if not root:
            return []
        
        queue = []  # node, height
        output = []
        
        queue.append(root)
        
        while len(queue) > 0:
            level_output = [node.val for node in queue]
            output.append(level_output)
            
            queue_size = len(queue)
            for _ in range(queue_size):
                node = queue.pop(0)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

        return output


    def levelOrder_1(self, root):
        # write your code here
        
        if not root:
            return []
        
        queue = []  # node, height
        output = []
        
        queue.append((root,0))
        
        while len(queue) > 0:
            node, h = queue.pop(0)
            
            if h > len(output) - 1:
                output.insert(h, [node.val])
            else:
                output[h].append(node.val)
            
            if node.left:
                queue.append((node.left, h+1))
            if node.right:
                queue.append((node.right, h+1))
        return output

s = Solution()

n1 = TreeNode(1)
n2 = TreeNode(2)
n3 = TreeNode(3)
n4 = TreeNode(4)
n1.left = n2
n1.right = n3
n2.right = n4
o = s.levelOrder(n1)
print(o)
