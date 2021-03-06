//最大连续子数组和
/*
输入一个整形数组，数组里有正数也有负数。数组中连续的一个或多个整数组成一个子数组，每个子数组都有一个和。 求所有子数组的和的最大值，要求时间复杂度为O(n)。

例如输入的数组为1, -2, 3, 10, -4, 7, 2, -5，和最大的子数组为3, 10, -4, 7, 2， 因此输出为该子数组的和18。
*/

//动态规划
//考虑加入一个新的值后，可能会
int MaxSubArray(int *a,int n)
{
	int currSum=a[0];	//加入当前元素后，可能产生新的最大值
	int maxSum=a[0];	//当前的最大值
	for(int i=1;i<n;++i)
	{
		if(currSum<0)	//舍去前面的累计
			currSum=a[i];
		else
			currSum+=a[i];
		if(currSum>maxSum)
			maxSum=currSum;
	}
	return maxSum;
}




/*
1 给定整型数组，其中每个元素表示木板的高度，木板的宽度都相同，求这些木板拼出的最大矩形的面积。并分析时间复杂度。

此题类似leetcode里面关于连通器的题，需要明确的是高度可能为0，长度最长的矩形并不一定是最大矩形，还需要考虑高度很高，但长度较短的矩形。如[5,4,3,2,4,5,0,7,8,4,6]中最大矩形的高度是[7,8,4,6]组成的矩形，面积为16。

2、环面上的最大子矩形

《算法竞赛入门经典》 P89 页。

3、最大子矩阵和

一个M*N的矩阵，找到此矩阵的一个子矩阵，并且这个子矩阵的元素的和是最大的，输出这个最大的值。如果所有数都是负数，就输出0。 例如：4*4的矩阵：

 0 -2 -7  0
 9  2 -6  2
-4  1 -4  1
-1  8  0 -2 

和最大的子矩阵是：

 9 2
-4 1
-1 8

最后输出和的最大值15。

http://blog.csdn.net/beiyeqingteng/article/details/7056687

4、允许交换两个数的位置 求最大子数组和。

来源：https://codility.com/cert/view/certDUMWPM-8RF86G8P9QQ6JC8X/details 。
*/