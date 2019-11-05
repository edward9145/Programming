class USet:
    x = {}
    def __init__(self, y):
        # self.x = {}
        self.y = y
    
    def union(self, node):
        self.x[node] = 1


u1 = USet(10)
u1.union("u1")
print("u1")
print(u1)
print(u1.x)
print(u1.y)


u2 = USet(20)
print("u2")
print(u2)
print(u2.x)
print(u2.y)
