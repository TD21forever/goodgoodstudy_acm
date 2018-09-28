/*
* @Author: TD21forever
* @Date:   2018-09-21 00:15:53
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-09-21 17:01:12
*/
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n", (1+n)*n/2);
	}
	return 0;
}