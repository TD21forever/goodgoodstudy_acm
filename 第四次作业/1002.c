/*
* @Author: TD21forever
* @Date:   2018-10-11 22:20:56
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-10-11 22:30:51
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	int m;
	scanf("%d", &m);
	long long int array[100];
	array[0] = 0;
	array[1] = 1;
	array[2] = 2;
	array[3] = 3;
	for(int i = 4; i < 51; i++)
	{
		array[i] = array[i - 1] + array[i - 2];
	}

	while(m--)
	{

		int a, b;
		scanf("%d %d", &a, &b);

		int t = b - a;
		printf("%lld\n", array[t]);
	}

	return 0;
}