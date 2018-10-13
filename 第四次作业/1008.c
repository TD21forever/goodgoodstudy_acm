/*
* @Author: TD21forever
* @Date:   2018-10-11 22:20:56
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-10-12 00:22:57
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	int m;
	scanf("%d", &m);
	long long int array[40];
	array[0] = 0;
	array[1] = 1;
	array[2] = 3;

	for(int i = 3; i < 40; i++)
	{
		array[i] = array[i - 1] + 2*array[i-2];
	}

	while(m--)
	{

		int a;
		scanf("%d", &a);
		printf("%lld\n", array[a]);
	}

	return 0;
}