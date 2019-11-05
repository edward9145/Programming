https://blog.csdn.net/yaoct/article/details/85263568

1671. play game
cat-only-icon
CAT Only
中文English
N individuals are playing games, each game has a referee and N-1 civilian players. Given an array A, A[i] represents that the player i needs to be at least a civilian A[i] times, returning the minimum number of games played.

Example
Example 1:

Input：A = [2, 2, 2, 2]
Output : 3
Explanation：
A[0] = 2 means that player 0 needs to be at least 2 times civilian
The first game: Player 0 serves as the referee, at this time A[0] = 0, A[1] = 1, A[2] = 1, A[3] =1
Second game: Player 1 serves as the referee, at this time A[0] = 1, A[1] = 1, A[2] = 2, A[3] = 2
The third game: Player 2 serves as the referee, at this time A[0] = 2, A[1] = 2, A[2] = 2, A[3] = 3
At this point, each player has met the requirements, so you can play three games.
Example 2:

Input：A = [84,53]
Output : 137
Explanation：
The first game: Player 1 serves as the referee, at this time A[0] = 1, A[1] = 0
......
The 31st game: Player 1 serves as the referee, at this time A[0] = 31, A[1] = 0
Thirty-second game: Player 0 serves as the referee, at this time A[1] = 31, A[1] = 1
Thirty-third game: Player 1 serves as the referee, at this time A[1] = 32, A[1] = 1
Thirty-fourth game: Player 0 serves as the referee, at this time A[1] = 32, A[1] = 2
......
The 137th game: Player 1 serves as the referee, at this time A[1] = 84, A[1] = 53
At this point, each player has met the requirements, so you can play 137 games.
Notice
∑Ai<=1e18
1 < n < 1000