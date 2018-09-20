/*
* @Author: TD21forever
* @Date:   2018-09-20 21:46:41
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-09-20 21:56:48
*/
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	int N,i,a,b;
	scanf("%d",&N);
	for (i= 0; i < N; ++i)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n", a+b);
	}
	return 0;
}