class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None

class Solution:
    """
    @param root: A Tree
    @return: Preorder in ArrayList which contains node values.
    """
    def preorderTraversal(self, root):
        # write your code here
        output = []
        self.addNode(root, output)
        return output
        
    def addNode(self, node, arr):
        if not node:
            return
        arr.append(node.val)
        self.addNode(node.left, arr)
        self.addNode(node.right, arr)

root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)

s = Solution()
result = s.preorderTraversal(root)
print(result)
