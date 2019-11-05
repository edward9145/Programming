"""https://www.cnblogs.com/twoheads/p/10557248.html
https://www.jiuzhang.com/solution/best-time-to-buy-and-sell-stock-iv/#tag-other
https://segmentfault.com/a/1190000004313629#articleHeader4

1691. Best Time to Buy and Sell Stock V
中文English
Given a stock n-day price, you can only trade at most once a day, you can choose to buy a stock or sell a stock or give up the trade today, output the maximum profit can reach.

Example
Example 1:

Given `a = [1,2,10,9]`, return `16`
Input:
[1,2,10,9]
Output:
16

Explanation:
you can buy in day 1,2 and sell in 3,4.
profit:-1-2+10+9 = 16 
Example 2:

Given `a = [9,5,9,10,5]`, return `5`
Input:
[9,5,9,10,5]
Output:
5

Explanation:
you can buy in day 2 and sell in 4.
profit:-5 + 10 = 5
Notice
1 \leq n \leq 100001≤n≤10000
"""
class Solution:
    """
    @param a: the array a
    @return: return the maximum profit
    """
    def getAns(self, a):
        # write your code here

# buy\sale   [1, 2, 10, 9]
#        1    0  1  9   8
#        2    -1 0  8   7
#        10   -9 -8 0   -1
#        9    -8 -7 1   0
        if not a or len(a) <= 1:
            return 0
        
        import queue as Q
        pq = Q.PriorityQueue()
        visited = set()
        total_profit = 0
        buy_sale = [[0]*len(a) for _ in range(len(a))]
        for buy in range(len(a)):
            for sale in range(buy,len(a)):  # O(n*n/2) = O(n*n)
                profit = a[sale] - a[buy]
                if profit > 0:   # pq always get the min one, reverse profit to get the max
                    pq.put((-profit, (buy,sale)))
                    buy_sale[buy][sale] = profit
        while not pq.empty():   # O(n*n/2) = O(n*n) 
            profit, (buy, sale) = pq.get()
            print(profit, (buy, sale))
            if buy not in visited and sale not in visited:
                total_profit -= profit
                visited.add(buy)
                visited.add(sale)

        for r in buy_sale:
            print(r)
        return total_profit
        
s = Solution()
ans = s.getAns([1,2,10,9])
print(ans)
ans = s.getAns([9,5,9,10,5])
print(ans)
ans = s.getAns([16,40,33,43,87,26,22,100,53,38,72,40,82,19,25,52,3,83])  # expected 375
print(ans)

"""
Input
Show Difference
[16,40,33,43,87,26,22,100,53,38,72,40,82,19,25,52,3,83]
Output
372
Expected
375
"""