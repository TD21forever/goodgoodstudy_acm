/*
* @Author: TD21forever
* @Date:   2018-12-20 19:51:48
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-12-20 20:30:59
*/

#include<bits/stdc++.h>
using namespace std;
int num_school;
int num_relation;
int boss_list[1005] = {};
int arr[1005];

int findboss(int a)//找到最高领导人
{
	int boss = a;
	while(boss_list[boss] != boss)
	{
		boss = boss_list[boss];
	}
	return boss;
}
void merge(int b, int a)
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
	while(scanf("%d%d", &num_school, &num_relation) == 2)
	{
		int cnt = 0;
		memset(arr,0,sizeof(int));
		for (int i = 0; i <= num_school; ++i)
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
		int p = 0;
		for (int i = 1; i <= num_school; ++i)
		{
			if (findboss(i) != 0)
			{
				cnt++;
				arr[p] = i;
				p++;
			}

		}
		printf("%d\n", cnt);
		int flag = 1;
		for (int i = 0; i <p; ++i)
		{
			printf("%d ", arr[i]);
		}

	}
	return 0;
}