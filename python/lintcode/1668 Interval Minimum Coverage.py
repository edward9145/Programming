https://www.jiuzhang.com/solution/interval-minimum-coverage/#tag-other-lang-python

1668. Interval Minimum Coverage
cat-only-icon
CAT Only
中文English
There are n intervals in number axis. Now we need to choose some points to make that there is at least one point in each interval.

Return the minimum number of chosen points.

Example
Example 1:

Input: [(1,5), (4,8), (10,12)]
Output: 2
Explanation: 
  Choose two points: 5, 10
  The first  interval [1, 5] contains 5
  The second interval [4, 8] contains 5
  The third  interval [10, 12] contains 10
Example 2:

Input: [(1,5), (4,8), (5,12)]
Output: 1
Explanation: All intervals contain 5
Notice
1 <= n <= 10^4
We guarantee that the given intervals are valid and the left and right endpoints of each interval are within the range of [0, 10 ^ 5].
They are closed intervals.

