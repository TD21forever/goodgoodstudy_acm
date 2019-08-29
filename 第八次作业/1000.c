/*
* @Author: TD21forever
* @Date:   2018-12-02 00:12:30
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-12-05 14:28:30
*/
//题目来自 https://www.bilibili.com/video/av36136952?from=search&seid=2483588059631739661
//背包问题可视化网站 http://karaffeltut.com/NEWKaraffeltutCom/Knapsack/knapsack.html
#include<stdio.h>
#include<stdlib.h>

int waste[6] = {0, 2, 3, 4, 5, 9}; //每个商品占用的体积
int value[6] = {0, 3, 4, 5, 8, 10}; //每个商品的价值
int B[6][21] = {0};
int dp[6] = {};

int main(int argc, char const *argv[])
{
	for (int item = 1; item <= 5; ++item)//这里想象脑海中有一个表格 行表示商品 列表示当前容量
	{
		for (int capacity = 1; capacity <= 20; ++capacity)
		{
			if (waste[item] >  capacity)//如果当前拿了一个商品它占用的体积 大于 当前背包的体积
			{
				B[item][capacity] = B[item - 1][capacity];//这个情况就等同于 没拿当前这个商品
			}
			else//如果当前这个商品可以拿  分为拿和不拿 两种情况
			{
				int value1 = B[item - 1][capacity - waste[item]] + value[item];//拿 等价于背包里内定了当前这个商品 等价于...
				int value2 = B[item - 1][capacity];//不拿
				if (value1 > value2)
				{
					B[item][capacity] = value1;
				}
				else
				{
					B[item][capacity] = value2;
				}
			}
		}
	}
	printf("%d\n", B[5][20]);
	return 0;
}

/*
int waste[6] = {0, 2, 3, 4, 5, 9}; //每个商品占用的体积
int value[6] = {0, 3, 4, 5, 8, 10}; //每个商品的价值
int B[6][21] = {0};
*/
//优化成一维数组
// int max(int a, int b)
// {
// 	return (a > b) ? a : b;
// }

// int main(int argc, char const *argv[])
// {
// 	for (int i = 1; i <= 5; ++i)
// 	{
// 		for (int capacity = 20; capacity >= waste[i]; capacity--)
// 		{
// 			dp[capacity] = max(dp[capacity], dp[capacity - waste[i]] + value[i]);
// 		}
// 	}
// 	printf("%d\n", dp[20]);
// 	return 0;
// }