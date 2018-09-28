/*
* @Author: TD21forever
* @Date:   2018-09-27 22:15:02
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-09-28 23:48:07
*/
#include<stdio.h>
#include<stdlib.h>


int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d", &n)==1)
	{
		if(n % 8 == 2 || n % 8 == 6)
		{
			printf("%s\n", "yes");
		}
		else
		{
			printf("%s\n", "no");
		}
	}
	return 0;
}