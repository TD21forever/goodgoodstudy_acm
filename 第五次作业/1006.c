#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    cout << "Hello world" << endl;
    return 0;
}



/*
* @Author: TD21forever
* @Date:   2018-10-24 21:19:58
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-10-25 18:05:02
*/


//已经可以求出长度 但是求不出从哪里到哪里
#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int weight;
	int speed;
	int num;
} mice;
int cmp(const void *a, const void *b)  //如果a和b不一样 从小到大排weight 如果一样 从大到小排speed
{
	mice *c = (mice *)a;
	mice *d = (mice *)b;

	if(c->weight != d->weight)
		return d->weight - c->weight;
	else
	{
		return c->speed - d->speed;
	}
}
int max(int a, int b)
{
	return a > b ? a : b;
}
int main(int argc, char const *argv[])
{
	mice s[100];
	int opt[1000] = {};
	int k = 1;

	while(scanf("%d %d", &s[k].weight, &s[k].speed) != EOF )
	{
		if (s[k].weight == -1 && s[k].speed == -1)
		{
			break;
		}
		s[k].num = k;
		k++;
	}
	qsort(s + 1, k - 1, sizeof(s[0]), cmp );
	s[0].weight = 0;
	s[0].speed = 0;
	s[0].num = 0;
	// for (int i = 0; i <= 9; ++i)
	// {
	// 	printf("%d %d\n", s[i].weight, s[i].speed );
	// }
	int pre[1000] = {};
	for (int i = k - 1; i >= 1 ; --i)
	{
		for(int j = i - 1; j >= 0; j--)
		{
			if (s[i].speed > s[j].speed && s[i].weight < s[j].weight)
			{
				pre[i] = j;
				break;
			}
		}
	}
	opt[0] = 0;
	opt[1] = 1;
	int res = 0;
	// int p = 0;
	// int mark[1000] = {};
	for (int i = 2; i <= k - 1; ++i)
	{
		// opt[i] = max(opt[pre[i]] + 1, opt[i - 1]);
		if ((opt[pre[i]] + 1) > opt[i - 1])//选
		{
			opt[i] = opt[pre[i]] + 1;
			// mark[p++] = s[i].num;

			
		}
		else
		{
			opt[i] = opt[i - 1];
		}

	}

	for (int i = 0; i < k; ++i)
	{
		if (res < opt[i])
		{
			res = opt[i];
		}
	}
	// int cnt = 0;
	// for (int i = k-1;i >=0;i--)
	// {
	// 	for(int j = i-1;j>0;j--)
	// 	{
	// 		if (s[i].speed > s[j].speed && s[i].weight < s[j].weight)
	// 		{
	// 			mark[cnt++] = s[i].num;
	// 			i=j;
	// 			printf("%d\n", cnt);
	// 			if (cnt == res)
	// 			{
	// 				for (int i = 0; i < cnt; ++i)
	// 				{
	// 					printf("%d\n", mark[i]);
	// 				}
	// 				break;
	// 			}
	// 		}
	// 	}
	// }
	// for (int i = 0; i < p; ++i)	
	// {
	// 	printf("%d\n", mark[i]);
	// }
	for (int i = 0; i <= k-1; ++i)
	{
		printf("%d\n", opt[i]);
	}

	return 0;
}




