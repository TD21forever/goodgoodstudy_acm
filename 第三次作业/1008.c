/*
* @Author: TD21forever
* @Date:   2018-10-01 00:00:45
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-10-01 00:31:59
*/
#include<stdio.h>
#include<stdlib.h>

int cmpfunc (const void *a, const void *b)
{
	return ( *(int *)a - * (int *)b );
}


int main(int argc, char const *argv[])
{

	int china[101];
	int japan[101];
	int n, c_sum, j_sum;
	while(scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}

		c_sum = 0;
		j_sum = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &china[i]);
		}
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &japan[i]);
		}
		qsort(china, n, sizeof(int), cmpfunc);

		qsort(japan, n, sizeof(int), cmpfunc);

		for (int i = 0; i < n; ++i)
		{
			if (china[i] == japan[i])
			{
				c_sum += 1;
				j_sum += 1;
			}
			else if(china[i] < japan[i])
			{
				j_sum += 2;
			}
			else
			{
				c_sum += 2;
			}
		}

		printf("%d vs %d\n", c_sum, j_sum);


	}
	return 0;
}