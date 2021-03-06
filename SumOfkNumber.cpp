/*
输入两个整数n和sum，从数列1，2，3.......n 中随意取几个数，使其和等于sum，
要求将其中所有的可能组合列出来。

思路：注意到取n，和不取n个区别即可，考虑是否取第n个数的策略，
可以转化为一个只和前n-1个数相关的问题。

如果取第n个数，那么问题就转化为“取前n-1个数使得它们的和为sum-n”，
对应的代码语句就是sumOfkNumber(sum - n, n - 1)；
如果不取第n个数，那么问题就转化为“取前n-1个数使得他们的和为sum”，
对应的代码语句为sumOfkNumber(sum, n - 1)。
*/

list<int>list1;
void SumOfkNumber(int sum, int n)
{
    // 递归出口
    if (n <= 0 || sum <= 0)
        return;

    // 输出找到的结果
    if (sum == n)
    {
        // 反转list
        list1.reverse();
        for (list<int>::iterator iter = list1.begin(); iter != list1.end(); iter++)
            cout << *iter << " + ";
        cout << n << endl;
    }

    list1.push_front(n);      //典型的01背包问题
    SumOfkNumber(sum - n, n - 1);   //“放”n，前n-1个数“填满”sum-n
    list1.pop_front();
    SumOfkNumber(sum, n - 1);     //不“放”n，n-1个数“填满”sum
}


//0-1背包问题
/*
0-1背包问题是最基础的背包问题，其具体描述为：有N件物品和一个容量为V的背包。
放入第i件物品耗费的费用是Ci，得到的价值是Wi。求解将哪些物品装入背包可
使价值总和最大。

分析：这是最基础的背包问题，特点是每种物品仅有一件，可以选择放或不放。
用子问题定义状态：即F[i, v]表示前i件物品恰放入一个容量为v
的背包可以获得的最大价值。则其状态转移方程便是：

F[i, v] = max{F[i-1, v], F[i-1, v-Ci ] + Wi}

方程的意义：“将前i件物品放入容量为v的背包中”这个子问题，
若只考虑第i件物品的策略（放或不放），
那么就可以转化为一个只和前 i-1 件物品相关的问题。即：

	如果不放第i件物品，那么问题就转化为“前i-1件物品放入容量为v的背包中”，
	价值为 F[i-1, v ]；
	如果放第i件物品，那么问题就转化为“前i-1件物品放入剩下的容量为v-Ci
	的背包中”，此时能获得的最大价值就是F[i-1, v-Ci]再加上通过放入
	第i件物品获得的价值Wi。
*/


/*1、《挑战程序设计竞赛》的开篇有个类似的抽签问题，挺有意思，题目如下：

将写有数字的n个纸片放入一个纸箱子中，然后你和你的朋友从纸箱子中抽取
4张纸片，每次记下纸片上的数字后放回子箱子中，如果这4个数字的和是m，
代表你赢，否则就是你的朋友赢。

请编写一个程序，当纸片上所写的数字是k1，k2，k3，k4，..，kn时，
是否存在抽取4次和为m的方案，如果存在，输出YES；否则，输出NO。

限制条件：

1 <= n <= 50
1 <= m <= 10^8
1 <= ki <= 10^8

思路：先把这n个纸片排序，时间复杂度为O(nlogn).然后从最大值n开始，
决策取不取n。
如果取n，那么问题就转化为“从前n-1个数中取3个数使它们的和等于m-n”，
下一次遍历可以先二分查找到小于m-n的最大值，再一次决策。
如果不取n，那么问题就转化成“从前n-1个数中取3个数使它们的和等于m”。
*/

/*
2、给定整数a1、a2、a3、...、an，判断是否可以从中选出若干个数，
使得它们的和等于k（k任意给定，且满足-10^8 <= k <= 10^8）。

分析：此题相对于本节“寻找满足条件的多个数”如出一辙，
不同的是此题只要求判断，不要求把所有可能的组合给输出来。
因为此题需要考虑到加上a[i]和不加上a[i]的情况，
故可以采用深度优先搜索的办法，递归解决。
*/


/*
有n个数，输出期中所有和为s的k个数的组合。
*/