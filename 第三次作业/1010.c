/*
* @Author: TD21forever
* @Date:   2018-09-30 23:05:14
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-10-01 00:37:17
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int pos;
	int du;
} List;

int cmpfunc (const void *a, const void *b)
{
	return ( (*(List *)b).du - (*(List *)a).du );
}


int main(int argc, char const *argv[])
{
	List l[20];
	int t, num;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		int flag = 1;
		int map[14][14] = {};
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &num);
			l[i].du = num;
			l[i].pos = i;
		}

		for (int i = 0; i < n; ++i) //每次都取头
		{
			qsort(l + i, n - i, sizeof(List), cmpfunc);
			// for (int i = 0; i < n; i++)
			// {
			// 	printf("%d", l[i].du);
			// }
			if (l[n - 1].du < 0)
			{
				flag = 0;
				printf("%s\n", "NO");
				break;
			}
			for (int j = 1; j <= l[i].du; ++j)
			{
				--l[i + j].du;                  //第i个是头 i+1  i+2 i+3 都要--
				int p_i = l[i].pos;
				int p_j = l[i + j].pos;
				map[p_i][p_j] = 1;
				map[p_j][p_i] = 1;

			}

		}
		if (flag)
		{
			printf("%s\n", "YES");
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					if (j == 0)
					{
						printf("%d", map[i][j]);
					}
					else
					{
						printf(" %d", map[i][j]);
					}
				}
				printf("\n");
			}
		}
		if ((n - 1) != 0)
		{
			printf("\n");
		}

	}
	return 0;
}