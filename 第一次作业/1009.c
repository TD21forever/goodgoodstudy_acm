/*
* @Author: TD21forever
* @Date:   2018-09-20 22:30:52
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-09-20 22:40:22
*/
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	int n,i,sum=0;
	while(scanf("%d",&n) == 1)
	{
		for (i =1 ; i <=n; ++i)
		{
			sum+=i;
		}
		printf("%d\n\n", sum);
		sum = 0;
	}
	return 0;
}