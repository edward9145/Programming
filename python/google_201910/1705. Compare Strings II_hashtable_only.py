"""
https://www.lintcode.com/problem/compare-strings-ii/description?_from=ladder&&fromId=127

Description
中文
English
One string is strictly smaller than another when the frequency of occurrence of the smallest character in the string is less than the frequency of occurrence of the smallest character in the comparison string.
For example,string "abcd" is smaller than string "aaa" because the smallest character (in lexicographical order) in "abcd" is 'a', with a frequency of 1, and the smallest character in "aaa" is also 'a',but with a frequency of 3. In another example, string "a" is smaller than string "bb" beacuse the smallest character in "a" is 'a' with a frequency of 1, and the smallest character in "bb" is 'b' with a frequency of 2.
Write a function that, given string A (which contains N strings delimited by ','), returns an array C of N integers. For 0 <= J < N, values of C[J] specify the number of strings in A which are strictly smaller than the comparison J-th string in B (starting from 0).

1 <= N, M <= 10000
1 <= length of any string contained by A or B <= 10
All the input strings comprise only lowercase English alphabet letters (a - z)
Have you met this question in a real interview?  
Example
Example 1:

Input: 
A = "abcd,aabc,bd"
B = "aaa,aa"
Output: [3, 2]	
Explanation: All the strings in the array are strictly smaller than "aaa" on the basis of the given comparison cirteria;
Strings "abcd" and "bd" are strictly smaller than "aa".
"""

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
        
        # 1 <= length of any string contained by A or B <= 10
        freq_A = [0]*10
        for a in int_arrA:
            freq_A[a] += 1
        
        # loop B 
            # index position of B, 
            # return index position
        output = []
        # print(int_arrA)
        # print(int_arrB)
        # print(freq_A)
        for b in int_arrB:
            num = 0
            for f in range(b):
                num += freq_A[f]
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


# "ab,a,aabc,bbd,ddde,eee"
# "aaaa"