/*
* @Author: DESKTOP-0VVB0MB$
* @Date:   2018-09-27 19:02:55
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-09-28 23:17:47
*/

// a+b 
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	int n,sum;
	while(scanf("%d",&n)==1)
	{	
		sum = 0;
		int i;
		for (i = 0; i <= n; ++i)
		{
			sum+=i;
		}

		printf("%d\n\n", sum);

	}
	return 0;
	
}