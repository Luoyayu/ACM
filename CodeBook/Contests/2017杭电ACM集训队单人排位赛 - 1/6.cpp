//yyf之贪吃蛇大作战
//模拟
贪吃蛇大作战是个很有意思的休闲游戏，最适合和妹子一起玩啦，故而yyf对此十分着迷。但多人游戏延迟高一直是个很大的问题，延迟发生前，yyf操控自己的蛇朝某个方向前进，现在想知道经过延迟时间t之后，自己的蛇是否依然活着（延迟期间yyf的蛇一直会朝一开始的方向前进）。

由于游戏较为复杂，现简化游戏的基本规则:
1) 每单位时间，每个玩家可以从上下左右4个方向中，选择一个方向进行移动，每单位时间前进一格。如果玩家没有操作，则此蛇沿着原方向前进一格。
2）贪吃蛇大作战中，每条贪吃蛇的头可以穿过自己的身体，但不能穿过别人的身体和墙，当某条蛇撞上其他蛇的身体，或者撞向墙壁，则会造成自己的死亡；如果两条蛇是正面相撞（蛇头正面撞向另一条蛇的正面），则两头蛇都会死亡。死亡的蛇会在下一个单位时间初从地图上瞬间消失。
3）同时，在这个游戏中会有许多糖果随机出现在地图中，每条蛇吃到这个糖果后身体长度会+1，增加的长度会出现在蛇移动一格前的最末端，最初蛇的长度为1，即一个蛇头。当增加的长度中有其他蛇的蛇头恰好撞向此格，则撞向此格的蛇死亡。
4）如果多条蛇撞向一个格子，这些蛇都死亡，如果此格子还有一个糖果，则这个糖果优先判给编号小的蛇吃。
以下为一些示意图，但没有包含所有情况，请仔细读题。


已知延迟期间其他玩家的操作，问t时刻后，yyf的贪吃蛇是否还活着

Input
每个样例只包含一组数据：
第一行，两个整数N,M，a，b代表地图的行数和列数，现存贪吃蛇的数量a以及糖果的数目b。
接下来a行，每行三个整数，x，y，z，给出每条蛇现存的位置和移动方向（取。）值为0-3，分别代表上、下、左、右）。每条的编号从上至下分别为1到k，其中yyf是编号为1的蛇，为简化题目，假设现存每条蛇长度都为1。
紧接着b行，每行两个整数u，v，代表每个糖果在地图上的位置。
第a+b+2行，两个整数T,L，代表延迟时间和在此期间的操作数目。
接下来L行，按时间从小到大的顺序给出一些操作，操作的格式如下
三个整数，time id direction，分别代表在time时刻，编号为id的蛇将当前前进的方向给为direction（取值为0-3，分别代表上、下、左、右）。如果编号为id的蛇已经死了，则无视此操作。操作序列中不含yyf的操作。
数据范围：
1<=N,M<=200
1<=T,L<=200
1<=a，b<=200
0<=Z，direciton<=3
题目所给的坐标（x，y），代表第x行，第y列。保证给出的坐标没有重复，且都在地图范围内。
 

Output
延迟发生的时刻为时间0，即问t时刻yyf是否还活着。若yyf还活着，输出“yyf will be forever!”，否则输出“laji game!”。注意输出结果不包含引号。
 

Sample Input
1 1 1 0 
1 1 1 
1 0 
5 5 2 2 
2 2 3
3 4 3 
2 3 
2 4 
3 1 
1 2 1
10 1 2 2 
10 1 1 
8 1 1 
6 1 
4 1 
6 0 
 

Sample Output
laji game! 
yyf will be forever!
laji game! 
