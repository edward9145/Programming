def merge(arr, low, mid, high):
    print(low, mid, high)
    print(arr[low:high+1])
    if not (low <= mid and mid < high):
        return

    temp = []
    l, r = low, mid+1
    # print(l, r)
    while l <= mid and r <= high:
        if arr[l] < arr[r]:
            temp.append(arr[l])
            l +=1
        else:
            temp.append(arr[r])
            r += 1

    while l <= mid:
        temp.append(arr[l])
        l +=1

    while r <= high:
        temp.append(arr[r])
        r += 1

    for i in range(low, high+1): # range(low, high+1) is [low, high+1), is [low, high]
        arr[i] = temp[i-low]
    print(arr)

def mergesort(arr, low, high):
    if low < high:
        mid = (low + high) / 2
        mergesort(arr, low, mid)
        mergesort(arr, mid+1, high)
        merge(arr, low, mid, high)

arr = [10, 80, 30, 90, 40, 50, 70]
arr = [10, 80, 30]
arr = [1,-1]

print(arr)
mergesort(arr, 0, len(arr) - 1)
print(arr)
