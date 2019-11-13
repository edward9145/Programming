"""
1) Left Rotation
2) Right Rotation

T1, T2 and T3 are subtrees of the tree 
rooted with y (on the left side) or x (on 
the right side)           
     y                               x
    / \     Right Rotation          /  \
   x   T3   - - - - - - - >        T1   y 
  / \       < - - - - - - -            / \
 T1  T2     Left Rotation            T2  T3
Keys in both of the above trees follow the 
following order 
 keys(T1) < key(x) < keys(T2) < key(y) < keys(T3)
So BST property is not violated anywhere.
"""


# Generic tree node class 
class TreeNode(object): 
    def __init__(self, val): 
        self.val = val 
        self.left = None
        self.right = None
        self.height = 1

# AVL tree class which supports the  
# Insert operation 
class AVL_Tree(object):
    
    def insert(self, root, key):
        if not root:
            return TreeNode(key)
        elif key < root.val:
            root.left = self.insert(root.left, key)
        else:
            root.right = self.insert(root.right, key)

        # step2
        root.height = 1 + max(self.getHeight(root.left), 
                            self.getHeight(root.right))
        
        # step3
        balance = self.getBalance(root)

        # step4
        if balance > 1 and key < root.left.val: # left left
            return self.rightRotate(root)
        
        if balance < -1 and key > root.right.val: # right right
            return self.leftRotate(root)
        
        if balance > 1 and key > root.left.val: # left right
            root.left = self.leftRotate(root.left)
            return self.rightRotate(root)
        
        if balance < -1 and key < root.right.val: # right left
            root.right = self.rightRotate(root.right)
            return self.leftRotate(root)
        
        # self.printByLevel(root)
        return root


    def leftRotate(self, x):
        y = x.right
        T2 = y.left

        # perform rotate
        y.left = x
        x.right = T2

        #update height
        x.height = 1 + max(self.getHeight(x.left),
                            self.getHeight(x.right))
        y.height = 1 + max(self.getHeight(y.left),
                            self.getHeight(y.right))
        
        return y

    def rightRotate(self, y):
        x = y.left
        T2 = x.right

        # perform rotate
        x.right = y
        y.left = T2

        #update height
        y.height = 1 + max(self.getHeight(y.left),
                            self.getHeight(y.right))
        x.height = 1 + max(self.getHeight(x.left),
                            self.getHeight(x.right))
        return x
        
    def delete(self, root, key):
        if not root:
            return root
        elif key < root.val:
            root.left = self.delete(root.left, key)
        elif key > root.val:
            root.right = self.delete(root.right, key)
        else:
            if root.left is None:
                temp = root.right
                root = None
                return temp
            elif root.right is None:
                temp = root.left
                root = None
                return temp
            temp = self.getMinValueNode(root.right)
            root.val = temp.val
            root.right = self.delete(root.right, temp.val)
        
        # step 1
        if root is None:
            return root
        
        # step 2
        root.height = 1 + max(self.getHeight(root.left),
                                self.getHeight(root.right))
        
        # step 3
        balance = self.getBalance(root)

        # step 4
        if balance > 1 and self.getBalance(root.left) >= 0:
            return self.rightRotate(root)
        if balance < -1 and self.getBalance(root.right) <= 0:
            return self.leftRotate(root)
        
        if balance > 1 and self.getBalance(root.left) < 0:
            root.left = self.leftRotate(root.left)
            return self.rightRotate(root)
        
        # right left
        if balance < -1 and self.getBalance(root.right) > 0:
            root.right = self.rightRotate(root.right)
            return self.leftRotate(root)

        return root
    
    def getMinValueNode(self, root):
        if root.left is None:
            return root
        return getMinValueNode(root.left)

    def getHeight(self, root):
        if not root:
            return 0
        return root.height
    
    def getBalance(self, root):
        if not root:
            return 0
        return self.getHeight(root.left) - self.getHeight(root.right)

    def insert_normal(self, root, key):
        if not root:
            return TreeNode(key)
        elif key < root.val:
            root.left = self.insert(root.left, key)
        else:
            root.right = self.insert(root.right, key)

        return root
    
    def preOrder(self, root):
        if not root: 
            return
  
        print("{0} ".format(root.val), end="") 
        self.preOrder(root.left) 
        self.preOrder(root.right) 
    
    def printByLevel(self, root):
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
        for r in output:
            print(r)
        return output

# Driver program to test above function 
myTree = AVL_Tree() 
root = None
  
root = myTree.insert(root, 10) 
root = myTree.insert(root, 20) 
root = myTree.insert(root, 30) 
root = myTree.insert(root, 40) 
root = myTree.insert(root, 50) 
root = myTree.insert(root, 25) 
  
"""The constructed AVL Tree would be 
            30 
           /  \ 
         20   40 
        /  \     \ 
       10  25    50"""
  
# Preorder Traversal 
print("Preorder traversal of the", 
      "constructed AVL tree is") 
myTree.printByLevel(root) 

root = myTree.delete(root, 50)
root = myTree.delete(root, 40)

myTree.printByLevel(root) 
