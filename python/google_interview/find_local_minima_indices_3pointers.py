# find local minima indices in an int array
# Time: O(n)
# Space: O(1)
# n is the length of input array

def local_minima(a):
    if not a:
        return []
    if len(a) == 1:
        return [0]

    a.insert(0, float('inf'))
    a.append(float('inf'))

    left = 0
    mid = 1
    right = 2
    minima = []
    # print("a", a)

    while right < len(a):
        while right < len(a) and a[right] == a[mid]:
            right += 1
        if a[left] > a[mid] and a[right] > a[mid]:
            minima.append(mid - 1)
        left = mid
        mid = right
    
    return minima

print(local_minima([])) # -> []
print(local_minima([1])) # -> [0]
print(local_minima([2,1])) # -> [1]
print(local_minima([1,2,1])) # -> [0,2]
print(local_minima([2,1,2])) # -> [1]
print(local_minima([1,1,1,1,0])) # -> [4]
print(local_minima([0,1,1,1,1])) # -> [0]
print(local_minima([1,1,2,2,3,0])) # -> [0,5]
print(local_minima([1,2,1,1,0])) # -> [0,4]
print(local_minima([1,1,2,2,3,3,2,2,1,1,0])) # -> [0,10]
print(local_minima([1,3,9,2,3,2,1,2,1,0])) # -> [0,3,6,9]
