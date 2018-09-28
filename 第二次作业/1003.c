/*
* @Author: TD21forever
* @Date:   2018-09-28 01:23:47
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-09-28 23:17:48
*/
#include<stdio.h>
#include<stdlib.h>

//多个数的最小公倍数

int gcd(int da,int xiao)
{
	int temp;
	while(xiao!=0)
	{
		temp = da%xiao;
		da = xiao;
		xiao = temp;
	}
	return da;
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		long long temp=1;
		while(n--)
		{
			int num;
			scanf("%d",&num);
			temp = temp/gcd(num,temp)*num;

		}
		printf("%I64d\n", temp);
	}

	return 0;
}

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b)
}