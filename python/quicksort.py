def partition(arr, low, high):
    i = low
    pivot = arr[high]
    for j in range(low, high):
        if arr[j] < pivot:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
    arr[i], arr[high] = arr[high], arr[i]
    return i

def printPivot(arr, idx):
    pArr = [ "   " ] * len(arr)
    pArr[idx] = "%3d"%idx
    print(arr)
    print(" ".join(pArr))

def quicksort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        printPivot(arr, pi)
        quicksort(arr, low, pi-1)
        quicksort(arr, pi+1, high)

arr = [10, 80, 30, 90, 40, 50, 70]
arr = [10, 80, 30]

print(arr)
quicksort(arr, 0, len(arr) - 1)
print(arr)
