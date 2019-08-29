/*
* @Author: TD21forever
* @Date:   2018-09-27 22:51:42
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-11-28 23:36:43
*/

//快速幂
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	long A,B,temp;
	while(scanf("%ld",&A)==1&&scanf("%ld",&B)==1)
	{
	
		if(A==0&&B==0)
		{
			break;
		}
		temp = 1;
		while(B!=0)
		{
			if(B%2==1)
			{
				temp*=A;//是奇数的话 乘个A 降一次 
				temp%=1000;
				B--;
				continue;
			}
			A=(A%1000)*(A%1000);
			B/=2;

		}

		printf("%ld\n",temp);
		
	}
	return 0;
}