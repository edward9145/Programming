def perm(a, l, r, result):
    if l==r:
        result.append(a.copy())
    else:
        for i in range(l, r+1):
            a[l],a[i] = a[i],a[l]
            perm(a, l+1, r, result)
            a[i],a[l] = a[l],a[i]

arr = [1,2,3]
result = []
perm(arr, 0, len(arr)-1, result)
print(result)
