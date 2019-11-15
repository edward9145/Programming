# find local minima in int array
# Time: O(n), Space: O(n)

def local_minima(a):
    if not a:
        return []
    
    union = [0]
    for i in range(1, len(a)):
        if a[i] != a[i-1]:
            union.append(i)

    print("union:", union)
    if len(union) == 1:
        return [union[0]]

    output = []
    if a[union[0]] < a[union[1]]:
        output.append(union[0])
    
    n = len(union)
    for j in range(1, n-1):
        if a[union[j-1]] > a[union[j]] and a[union[j]] < a[union[j+1]]:
            output.append(union[j])
    
    if a[union[n-1]] < a[union[n-2]]:
        output.append(union[n-1])
    
    return output

print(local_minima([1,2,1]))
print(local_minima([2,1,2]))
print(local_minima([1,1,1,1,1,1,1,0]))
print(local_minima([1,1,2,2,3,0]))
print(local_minima([1,2,1,1,0]))
