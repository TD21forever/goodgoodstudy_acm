/*
* @Author: TD21forever
* @Date:   2018-12-05 10:41:31
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-12-05 14:19:56
*/

/*

告诉你有一千万个人，告诉了你从中选取有n对，求相互认识的人最多的那个对有多少人

从一个大的集合里挑一部分人
*/
#include<iostream>
#include<string.h>
using namespace std;
#define MAX 200000
int boss_list[MAX];
int under[MAX];//手下
int mark[MAX];
int max_;
int findboss(int x)
{
	int boss = x;
	while(boss != boss_list[boss])
	{
		boss = boss_list[boss];
	}
	boss_list[x] = boss;
	return boss;
}
void merge(int a, int b)
{
	int x = findboss(a);
	int y = findboss(b);
	if (x != y)
	{
		under[y] += under[x]; //y的手下就变多了
	}
	boss_list[x] = y;//x的老板是y
	if (under[x] > max_)//看哪个老板手下的人多
	{
		max_ = under[x];
	}
	if (under[y] > max_ )
	{
		max_ = under[y];
	}
}

int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d", &n) == 1)//输入有n对
	{

		if(n == 0) //输入0返回1
		{
			printf("1\n");
			continue;
		}
		max_ = 0;
		for (int i = 0; i < MAX; ++i)
		{
			boss_list[i] = i;//每个人都是自己的老板
			under[i] = 1;//每个人的手下只有一个人
		}
		while(n--)
		{
			int a;
			int b;
			scanf("%d %d", &a, &b);
			mark[a] = 1;//mark表示这些人都是留下来的 等下我只要遍历这些留下来的人就好了
			mark[b] = 1;
			merge(a, b);
		}
		printf("%d\n", max_);
		memset(mark, 0, sizeof(mark));


	}

	return 0;
}