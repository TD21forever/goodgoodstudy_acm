/*
* @Author: TD21forever
* @Date:   2018-09-20 22:13:00
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-09-20 22:22:07
*/
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	int N,i,M,j,a,sum=0;
	scanf("%d",&N);
	for (i = 0; i < N; ++i)
	{
		scanf("%d",&M);
		for (j = 0; j < M; ++j)
		{
			scanf("%d",&a);
			sum+=a;
		}
		printf("%d\n", sum);
		sum = 0;
	}


	return 0;
}