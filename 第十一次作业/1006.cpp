/*
* @Author: TD21forever
* @Date:   2018-12-14 17:19:43
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-12-14 18:14:31
*/
#include<iostream>
#include<string.h>
using namespace std;

#define P 0
#define N 1

int array[1200];

int main(int argc, char const *argv[])
{
	memset(array, 0, sizeof(array));
	int money;
	int add;
	while(scanf("%d%d", &money, &add) !=EOF )
	{
		array[0] = P;
		int flag = 0;
		for (int i = 1; i <= money; ++i)
		{
			for (int j = 1; j <= add; ++j)
			{
				if (i - j < 0)
				{
					flag = 1;
					array[i] = N;
					break;
				}
				else
				{
					int pos = i - j;
					if (array[pos] == P)
					{
						flag = 1;
						array[i] = N;
						break;
					}
				}
			}
			if (!flag)
			{
				array[i] = N;
			}
		}
		if (array[money] == P) printf("none\n");
		else
		{
			for (int i = 1; i <= add ; ++i)
			{
				if ( money - i <= 0 || array[money - i] == P )
				{
					if (i + 1 > add)
					{
						printf("%d", i);
					}
					else
						printf("%d ", i);
				}
			}
			printf("\n");
		}
		for (int i = 0; i <= money; ++i)
		{
			printf("%d ", array[i]);
		}
	}
	return 0;
}