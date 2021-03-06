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
        if not a or len(a) <= 1:
            return 0
            
        total_profit = 0
        while len(a) > 0:
            profit, sale_id, buy_id = self.maxProfit(a)
            if profit == 0:
                break
            print(a)
            print("profit: %d\n sale: a[%d]=%d\n buy: a[%d]=%d" % (profit, sale_id, a[sale_id], buy_id, a[buy_id]))
            if sale_id > buy_id:
                a.pop(buy_id)
                a.pop(sale_id-1)
            else:
                a.pop(sale_id)
                a.pop(buy_id-1)
            print(a)
            total_profit += profit
        return total_profit
    
    def maxProfit(self, prices):
        if not prices or len(prices) == 1:
            return 0, 0, 0
        sale_id = 0
        buy_id = 0
        minPrice = prices[0]
        maxPro = 0
        for i in range(len(prices)):
            if minPrice > prices[i]:
                minPrice = prices[i]
                # buy_id = i
            if maxPro < prices[i] - minPrice:
                maxPro = prices[i] - minPrice
                sale_id = i
        buy_id = prices.index(prices[sale_id] - maxPro)
        return maxPro, sale_id, buy_id


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