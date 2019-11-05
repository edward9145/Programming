# 480. Binary Tree Paths
# Description
# 中文
# English
# Given a binary tree, return all root-to-leaf paths.

# Have you met this question in a real interview?  
# Example
# Example 1:

# Input：{1,2,3,#,5}
# Output：["1->2->5","1->3"]
# Explanation：
#    1
#  /   \
# 2     3
#  \
#   5
# Example 2:

# Input：{1,2}
# Output：["1->2"]
# Explanation：
#    1
#  /   
# 2     
# Related Problems
# DifficultyEasy
# Total Accepted33587
# Total Submitted90294
# Accepted Rate37%
#  Show Tags
#  Company
#   
# 480. Binary Tree Paths
# 中文English
# Given a binary tree, return all root-to-leaf paths.

# Example
# Example 1:

# Input：{1,2,3,#,5}
# Output：["1->2->5","1->3"]
# Explanation：
#    1
#  /   \
# 2     3
#  \
#   5
# Example 2:

# Input：{1,2}
# Output：["1->2"]
# Explanation：
#    1
#  /   
# 2     
# {1,2,3,#,5}


"""
Definition of TreeNode:
"""
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None


class Solution:
    """
    @param root: the root of the binary tree
    @return: all root-to-leaf paths
    """
    def binaryTreePaths(self, root):
        # write your code here
        if not root:
            return []
        
        path_list = []
        self.preorder(root, path_list, [])
        return path_list
        
    def preorder(self, node, path_list, path):
        if not node:
            return

        if node.left is None and node.right is None:
            # is leaf
            path.append(str(node.val))
            print(path)
            path_list.append("->".join(path))
            return
        
        path.append(str(node.val))
        self.preorder(node.left, path_list, path.copy())
        self.preorder(node.right, path_list, path.copy())
        

s = Solution()
# Input：{1,2,3,#,5}
# Output：["1->2->5","1->3"]
# Explanation：
#    1
#  /   \
# 2     3
#  \
#   5

root = TreeNode(1)
n2 = TreeNode(2)
n3 = TreeNode(3)
n5 = TreeNode(5)
root.left = n2
root.right = n3
n2.right = n5

l = s.binaryTreePaths(root)
print(l)

