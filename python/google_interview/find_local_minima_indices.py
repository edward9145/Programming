# find local minima indices in an int array
# Time: O(n)
# Space: O(n)
# n is the length of input array

def local_minima(a):
    if not a:
        return []
    
    # store the first index of repeat numbers
    # then we can skip repeat number checking
    no_dup = [0]
    for i in range(1, len(a)):
        if a[i] != a[i-1]:
            no_dup.append(i)

    if len(no_dup) == 1:
        return [no_dup[0]]

    output = []

    if a[no_dup[0]] < a[no_dup[1]]:
        output.append(no_dup[0])
    
    n = len(no_dup)
    for j in range(1, n-1):
        if a[no_dup[j]] < a[no_dup[j-1]] \
        and a[no_dup[j]] < a[no_dup[j+1]]:
            output.append(no_dup[j])
    
    if a[no_dup[n-1]] < a[no_dup[n-2]]:
        output.append(no_dup[n-1])
    
    return output

print(local_minima([])) # -> [0]
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
