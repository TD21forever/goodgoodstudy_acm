/*
* @Author: TD21forever
* @Date:   2018-10-11 22:43:28
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-10-11 23:13:29
*/
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	long long int array[100];
	array[0] = 0;
	array[1] = 1;
	array[2] = 2;
	array[3] = 3;
	for(int i = 4; i < 51; i++)
	{
		array[i] = array[i - 1] +  array[i - 2];
	}
	int a;
	while(scanf("%d", &a) == 1)
	{
		printf("%lld\n", array[a]);
	}

	return 0;

}