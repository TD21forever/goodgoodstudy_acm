/*
* @Author: TD21forever
* @Date:   2018-10-11 21:57:11
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-10-11 22:04:21
*/
#include<stdio.h>
#include<stdlib.h>

int f(int m)
{
	int res;
	if(m == 1)
	{
		return 0;
	}
	else if(m == 2)
	{
		return 1;
	}
	else if(m == 3)
	{
		return 2;

	}
	else
	{
		res = f(m - 1) + f(m - 2);
	}
	return res;
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int m;
		scanf("%d", &m);
		int res = f(m);
		printf("%d\n", res);
	}
	return 0;
}