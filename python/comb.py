def comb(arr, r, start, end, index, data):
    if index == r:
        print(data)
        return
    
    i = start
    while i <= end and end-i+1 >= r-index:
        data[index] = arr[i]
        comb(arr, r, i+1, end, index+1, data)
        # while i < end-1 and arr[i] == arr[i+1]:
        #      i += 1
        i += 1

arr = [1,2,2]
r = 2
data = [0]*r
comb(arr, r, 0, len(arr)-1, 0, data)
# print(data)

