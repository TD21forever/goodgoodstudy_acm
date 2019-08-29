/*
* @Author: TD21forever
* @Date:   2018-11-29 21:48:02
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-11-29 23:50:06
*/
#include<stdio.h>
#include<stdlib.h>


typedef struct Node
{
	int x;
	int y;
	int distance;
} Node;
Node node[5000];
int boss_list[1050];

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

int cmp( const void *a, const void *b)
{
	return (*(Node *)a).distance > (*(Node *)b).distance ? 1 : -1;
}

int main(int argc, char const *argv[])
{
	int N, n; //N是一共有多少个村庄,n是N个村庄最多会有多少条路
	while(scanf("%d", &N) == 1)
	{

		if (N == 0)
		{
			break;
		}
		int sum = 0;
		int cnt = 0;
		n = N * (N - 1) / 2;
		for (int i = 1; i <= N; ++i)
		{
			boss_list[i] = i;//初始化
		}
		for (int j = 0; j < n; ++j)
		{
			scanf("%d %d %d", &node[j].x, &node[j].y, &node[j].distance);
		}
		qsort(node,n, sizeof(node[0]), cmp);
		// printf("%d %d %d\n", node[0].x, node[0].y, node[0].distance);
		for (int i = 0; i < n ; ++i)
		{
			// if (cnt == N - 1)
			// {
			// 	break;
			// }
			if (findboss(node[i].x) != findboss(node[i].y))//因为已经从小到大排序了  只要他们的老板不是同一个 就拉他们入伙
			{
				merge(node[i].x, node[i].y);
				sum += node[i].distance;
				// cnt++;
			}
		}
		printf("%d\n", sum);
	}

	return 0;
}