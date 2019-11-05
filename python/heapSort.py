def heapify(A, idx, end):
    left = idx*2 + 1
    right = idx*2 + 2
    maxIdx = idx
    if left < end and A[left] > A[idx]:
        maxIdx = left
    if right < end and A[right] > A[maxIdx]:
        maxIdx = right
    if maxIdx != idx:
        A[idx],A[maxIdx] = A[maxIdx],A[idx]
        heapify(A, maxIdx, end)

def buildHeap(A):
    n = len(A)
    for i in range(n//2-1, -1, -1):
        heapify(A, i, n)
        # print A

def heapSort(A):
    buildHeap(A)
    n = len(A)
    for i in range(0, n):
        A[0], A[n-i-1] = A[n-i-1], A[0]
        heapify(A, 0, n-i-1)

heap = [3,1,6,7,9,2,4,8,5]
buildHeap(heap)
print(heap)

h = 0
while (1<<h) <= len(heap):
    print(heap[(1<<h)-1:(1<<(h+1))-1])
    h += 1

heapSort(heap)
print(heap)
