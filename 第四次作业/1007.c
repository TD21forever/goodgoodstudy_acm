/*
* @Author: TD21forever
* @Date:   2018-10-11 22:20:56
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-10-14 17:36:22
*/

#include<stdio.h>
#include<stdlib.h>
//悼念512汶川大地震遇难同胞——重建希望小学
int main(int argc, char const *argv[])
{
	int m;
	scanf("%d", &m);
	long long int array[40];
	array[0] = 0;
	array[1] = 1;
	array[2] = 3;

	array[3] = 5;

	for(int i = 4; i < 40; i++)
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