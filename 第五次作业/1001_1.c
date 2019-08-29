/*
* @Author: TD21forever
* @Date:   2018-10-23 00:05:31
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-10-23 19:04:03
*/
#include<stdio.h>
#include<stdlib.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int main(int argc, char const *argv[])
{
	int n;
	int array[100][100];
	int c;
	scanf("%d", &c);
	while(c--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				scanf("%d", &array[i][j]);
			}
		}
		for (int i = n - 2; i >= 0; --i)
		{
			for (int j = 0; j <= i; ++j)
			{
				array[i][j] += max(array[i + 1][j], array[i + 1][j + 1]);
			}
		}
		printf("%d\n",array[0][0] );

	}


	return 0;
}