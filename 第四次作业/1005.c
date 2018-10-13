/*
* @Author: TD21forever
* @Date:   2018-10-11 22:20:56
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-10-11 23:20:44
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	int m;
	scanf("%d", &m);
	long long int array[10020];
	array[0] = 0;
	array[1] = 2;

	for(int i = 2; i < 10020; i++)
	{
		array[i] = array[i - 1] + 4*(i-1)+1;
	}

	while(m--)
	{

		int a;
		scanf("%d", &a);

		printf("%lld\n", array[a]);
	}

	return 0;
}