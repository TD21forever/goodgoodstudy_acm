/*
* @Author: TD21forever
* @Date:   2018-12-05 10:05:31
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-12-05 10:33:43
*/
#include<stdio.h>
#include<stdlib.h>

int num_people;
int num_relation;
int boss_list[1005];

int findboss(int a)//找到最高领导人
{
	int boss = a;
	while(boss_list[boss] != boss)
	{
		boss = boss_list[boss];
	}
	return boss;
}
void merge(int a, int b)
{
	int x = findboss(a);
	int y = findboss(b);
	if (x != y)
	{
		boss_list[x] = y;
	}

}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int cnt = 0;
		scanf("%d %d", &num_people, &num_relation);
		for (int i = 1; i <= num_people; ++i)
		{
			boss_list[i] = i;//每个人是自己的老板
		}
		for (int j = 1; j <= num_relation; ++j)
		{
			int a;
			int b;
			scanf("%d %d", &a, &b);
			merge(a, b);
		}
		for (int i = 1; i <= num_people; ++i)
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