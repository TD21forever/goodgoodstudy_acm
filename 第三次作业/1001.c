/*
* @Author: TD21forever
* @Date:   2018-09-29 21:22:13
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-09-30 12:49:31
*/

//  典型贪心算法 老鼠与猫的交易
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int food;
	int money;
	double res ;
} List;
int main(int argc, char const *argv[])
{
	List l[1000];
	List temp;
	int m, n, i, j;
	double get;
	while(scanf("%d", &m) == 1 && scanf("%d", &n) == 1)
	{
		get = 0;
		if(m == -1 && n == -1)
		{
			break;
		}

		for (i = 0; i < n; ++i)
		{
			scanf("%d %d", &l[i].food, &l[i].money);
			l[i].res = (double) l[i].food / (double) l[i].money;
		}

		for (i = 0; i < n - 1; ++i)
		{
			for (j = 0; j < n - i - 1; ++j)
			{
				if(l[j].res < l[j + 1].res)
				{
					temp = l[j];
					l[j] = l[j + 1];
					l[j + 1] = temp;
				}
			}
		}

		i = 0;
		for(i = 0; i < n; i++)  //应该用for循环遍历来做 不应该用m==0来判断 例如 0 1 1 0
		{
			if(m >= l[i].money)
			{
				m -= l[i].money;
				get += l[i].food;
			}
			else
			{
				get += l[i].res * m; 
				break;
			}
		}

		printf("%.3lf\n", get );



	}
	return 0;
}
