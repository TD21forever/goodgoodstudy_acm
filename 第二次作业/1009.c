/*
* @Author: TD21forever
* @Date:   2018-09-27 22:33:27
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-09-28 23:17:48
*/
#include<stdio.h>
#include<stdlib.h>

//两个数的最小公倍数

int main(int argc, char const *argv[])
{
	int n, m, max, min,temp;
	while(scanf("%d", &n) == 1 && scanf("%d", &m) == 1)
	{

		if(n < m)
		{
			min = n;
			max = m;
		}
		else
		{
			min = m;
			max = n;
		}
		temp = max;
		while(max % min != 0)
		{
			max += temp;
		}
		printf("%d\n", max);

	}
	return 0;
}