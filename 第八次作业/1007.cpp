/*
* @Author: TD21forever
* @Date:   2018-12-04 21:03:16
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-12-05 14:46:57
*/
#include<iostream>
#include<string.h>
using namespace std;

/*

解题思路：这道题也是01背包问题，在最后的计算结果方面：假设他向两所大学申请，得到offer的概率分别是a，b，他不能获得offer的概率为：（1-a）*（1-b）,所以他能获得offer的概率是1-（1-a）*（1-b）
*/

int waste[10005];
double value[10005];
double B[10005] = {};
double min_(double a,double b)
{
	return a<b?a:b;
}

int main(int argc, char const *argv[])
{
	int num_school;
	int money;
	while(scanf("%d %d", &money, &num_school),money!=0||num_school!=0)//坑爹啊尼玛啊 两个有一个为零就wa 是这么写的！！
	{
		memset(waste, 0, sizeof(waste));//memset只有-1和0可以初始化
		for (int i = 0; i <= num_school; ++i)
		{
			value[i] = 1;
		}
		for (int j = 0; j <= money; ++j)
		{
			B[j] = 1;//
		}
		for (int i = 1; i <= num_school; ++i)
		{
			scanf("%d%lf", &waste[i], &value[i]);
			value[i] = 1 - value[i];//拿不到合同的概率
		}
		for (int now = 1; now <= num_school; ++now)
		{
			for (int capacity = money; capacity >= waste[now]; --capacity)
			{
				B[capacity] = min_(B[capacity], B[capacity - waste[now]] * value[now]);//一份合同都拿不到
			}
		}
		printf("%.1f%%\n", (1 - B[money]) * 100);

	}
	return 0;
}