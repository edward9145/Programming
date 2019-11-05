"""
https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
https://blog.csdn.net/qq_38410730/article/details/81667885

C: capacity of the knapSack
wt: item weights
val: item values
n: item count
"""
def knapSack(C, wt, val, n):
    K = [[0]*(C+1) for i in range(n+1)]

    for i in range(n+1):
        for w in range(C+1):
            if i==0 or w==0:
                K[i][w] = 0
            elif wt[i-1] <= w:
                K[i][w] = max(K[i-1][w],   # not pick item i
                            K[i-1][w-wt[i-1]] + val[i-1]) # pick item i
            else:
                K[i][w] = K[i-1][w]
        for k in K:
            print(k)
        print()

    find = findItems(K, C, wt, val, n)
    print(find)

    return K[n][C]

def findItems(K, C, wt, val, n):
    find_items = []
    curr_capacity = C
    for i in range(n, 0, -1):
        item_id = i-1
        weight_without_i = curr_capacity - wt[item_id]
        if K[i-1][weight_without_i] + val[item_id] == K[i][curr_capacity]:
            find_items.append(item_id)
            curr_capacity -= wt[item_id]
    return find_items

val = [6, 10, 12] 
wt = [1, 2, 3] 
C = 6 # Capacity
n = len(val) # n items
print(knapSack(C, wt, val, n))