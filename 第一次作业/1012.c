/*
* @Author: TD21forever
* @Date:   2018-09-20 22:20:50
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-09-20 23:14:56
*/
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	int N, i,a, multi = 1;
	while(scanf("%d", &N) == 1)
	{
		for (i = 0; i < N; ++i)
		{
			scanf("%d", &a);
			if(a%2==1)
			{
				multi *= a;
			}
		}
		printf("%d\n", multi);
		multi = 1;

	}


	return 0;
}