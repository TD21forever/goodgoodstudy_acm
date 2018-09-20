/*
* @Author: TD21forever
* @Date:   2018-09-20 21:58:15
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-09-20 22:01:27
*/
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	int a,b;
	while(scanf("%d %d",&a,&b))
	{
		if(a==0&&b==0)
		{
			break;
		}
		printf("%d\n",a+b);
	}
	return 0;
}