/*
* @Author: TD21forever
* @Date:   2018-09-20 22:02:04
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-09-20 22:12:29
*/
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	int N,a,i,sum=0;
	
	while(scanf("%d",&N)==1)
	{
		if(N==0)
		{
			break;
		}
		for (i = 0; i < N; ++i)
		{
			scanf("%d",&a);
			sum+=a;
		}
		printf("%d\n", sum);
		sum = 0;
		
	}
	return 0;
}