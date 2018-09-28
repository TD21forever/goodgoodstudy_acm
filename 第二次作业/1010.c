/*
* @Author: DESKTOP-0VVB0MB$
* @Date:   2018-09-27 21:26:47
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-09-27 21:56:33
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char const *argv[])
{
	int n,m,i;
	double sum,temp;
	while(scanf("%d",&n)==1&&scanf("%d",&m)==1)
	{
		temp = n;
		sum = 0;
		for (i = 0; i < m; ++i)
		{
			sum+=temp;
			temp = sqrt(temp);
		}
		printf("%.2lf\n",sum);
	}
	return 0;

}