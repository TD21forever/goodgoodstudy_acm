/*
* @Author: TD21forever
* @Date:   2018-10-01 00:55:56
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-10-03 08:27:47
*/

//贪心算法卖粮食 类似1001 
#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int price;
	int kg;
} List;
int main(int argc, char const *argv[])
{
	List l[1001];
	List temp;
	int t;
	int m, n, i, j;
	double get;
	scanf("%d", &t);
	while(t--)
	{
		get = 0;
		scanf("%d", &m);
		scanf("%d", &n);

		for (i = 0; i < n; ++i)
		{
			scanf("%d %d", &l[i].price, &l[i].kg);
		}

		for (i = 0; i < n - 1; ++i)  //交换
		{
			for (j = 0; j < n - i - 1; ++j)
			{
				if(l[j].price > l[j + 1].price)
				{
					temp = l[j];
					l[j] = l[j + 1];
					l[j + 1] = temp;
				}
			}
		}
		for(i = 0; i < n; i++)   //如果能买完这一家的米 那就买完他 
		{
			if (m > l[i].price * l[i].kg)
			{
				get += l[i].kg;
				m -= l[i].price * l[i].kg;
			}
			else
			{
				get += (double)m / l[i].price;  //如果卖不完 那就把钱花完
				break;
			}
		}

		printf("%.2lf\n", get );


	}

	return 0;
}
