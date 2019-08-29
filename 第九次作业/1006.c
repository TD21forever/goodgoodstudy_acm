/*
* @Author: TD21forever
* @Date:   2018-11-29 21:06:26
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-12-01 01:51:40
*/
#include<stdio.h>
#include<stdlib.h>

int n, m;

//n个城镇 m条路
int boss_list[1002];

int findboss(int x)
{
	int boss = x;
	while(boss_list[boss] != boss)
	{
		boss = boss_list[boss];
	}
	return boss;
}

void merge(int a, int b)
{
	a = findboss(a);//a说我问问老板的意见
	b = findboss(b);//b说我问问老板的意见
	if (a != b)//如果a和b的老板是同一个 那么他们本来就在一个集合里
	{
		boss_list[a] = b;//否则的话就合并了
	}
}
int main(int argc, char const *argv[])
{
	while(scanf("%d", &n) == 1)
	{
		int cnt = -1;
		int a,b;
		if (n == 0 )
		{
			break;
		}
		for (int i = 1; i <= n; ++i)
		{
			boss_list[i] = i;
		}
		scanf("%d", &m);
		while(m)
		{
			scanf("%d %d", &a, &b);
			merge(a, b);
			m--;
		}
		for (int i = 1; i <= n ; ++i)
		{
			if (boss_list[i] == i)
			{
				cnt++;
			}
		}
		printf("%d\n", cnt);

	}

	return 0;
}