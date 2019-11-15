class Solution:
    """
    @param A: a string
    @param B: a string
    @return: returns an array C of N integers
    """
    def compareStringii(self, A, B):
        # write your code here
        if not B:
            return []
        arr_B = B.split(',')
        
        if not A:
            return [0]*len(arr_B)
        arr_A = A.split(',')
        
        # convert A, B to int arr
        int_arrA = [0]*len(arr_A)
        for i in range(len(arr_A)):
            int_arrA[i] = self.convertInt(arr_A[i])
            
        int_arrB = [0]*len(arr_B)    
        for j in range(len(arr_B)):
            int_arrB[j] = self.convertInt(arr_B[j])
        
        # sort A
        int_arrA.sort()
        
        # loop B 
            # index position of B, 
            # return index position
        output = []
        print(int_arrA)
        print(int_arrB)
        for b in int_arrB:
            num = self.findPos(int_arrA, 0, len(int_arrA)-1, b)
            output.append(num)
        return output
            
            
    def convertInt(self, string):
        alphabet = [0]*26
        ch_list = list(string)
        for c in ch_list:
            alphabet[ord(c) - ord('a')] += 1
        convertTo = 0
        for i in range(26):
            if alphabet[i] > 0:
                convertTo = alphabet[i]
                break
        return convertTo
        
    def findPos(self, arr, low, high, target):
        pos = 0
        while low <= high:
            mid = (low+high) // 2
            if target == arr[mid]:
                pos = mid
                break
            elif target < arr[mid]:
                high = mid -1
                pos = high
            else:
                low = mid + 1
                pos = low
        # case [1,2,2,2,3], target: 2
        if pos<len(arr) and target == arr[pos]:
            while pos > 0 and arr[pos] == arr[pos-1]:
                pos -= 1
        # case [1,3,3,3,4], target: 2
        return pos

        