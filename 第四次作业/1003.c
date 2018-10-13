/*
* @Author: TD21forever
* @Date:   2018-10-11 22:43:28
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-10-11 22:55:15
*/
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	long long int array[100];
	array[0] = 0;
	array[1] = 3;
	array[2] = 6;
	array[3] = 6;//3的时候不满足
	for(int i = 4; i < 51; i++)
	{
		array[i] = array[i - 1] + 2 * array[i - 2];
	}
	int a;
	while(scanf("%d", &a) == 1)
	{
		if (a == 1)
		{
			printf("3\n");
		}
		else
		{
			printf("%lld\n", array[a]);
		}

	}

	return 0;

}