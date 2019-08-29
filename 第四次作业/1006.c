/*
* @Author: TD21forever
* @Date:   2018-10-11 22:20:56
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-10-14 17:36:24
*/

//母牛的故事
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	
	long long int array[40];
	array[0] = 0;
	array[1] = 1;
	array[2] = 2;
	array[3] = 3;


	for(int i = 4; i < 40; i++)
	{
		array[i] = array[i - 1] + array[i-3];
	}
	int a;
	while(scanf("%d", &a)==1)
	{
		if (a==0)
		{
			break;
		}
		printf("%lld\n", array[a]);
	}

	return 0;
}