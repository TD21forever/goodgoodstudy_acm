/*
* @Author: TD21forever
* @Date:   2018-09-29 22:42:40
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-10-03 08:27:48
*/
#include<stdio.h>
#include<stdlib.h>

//搬桌子

int main(int argc, char const *argv[])
{
	int t, max;
	scanf("%d", &t);
	while(t--)
	{
		max = 0;
		int n, start, end, i, j;
		int a[200] = {};
		scanf("%d", &n);
		while(n--)
		{
			scanf("%d %d", &start, &end);
			i = (start - 1) / 2;
			j = (end - 1) / 2;
			if (i > j)
			{
				for (; i >= j; --i)
				{
					a[i] += 1;
				}
			}
			else
			{
				for (; i <= j; ++i)
				{
					a[i] += 1;
				}

			}

		}
		for (int i = 0; i < 200; ++i)
		{
			if(a[i] > max)
			{
				max = a[i];
			}
		}
		printf("%d\n", max * 10);

	}
	return 0;
}