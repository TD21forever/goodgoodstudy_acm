/*
* @Author: TD21forever
* @Date:   2018-09-27 23:51:31
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-09-28 23:48:07
*/
#include<stdio.h>
#include<stdlib.h>

//吃糖果
int main(int argc, char const *argv[])
{
	int T,N,num,max;
	long long  sum; // 用 long long；
	scanf("%d", &T);
	int i, j;
	for(i = 0; i < T; i++)
	{
		sum = 0;
		max = 0;
		scanf("%d", &N); 

		for(j = 0; j < N; j++)
		{
			scanf("%d", &num);
			if(num >= max)
			{
				max = num;
			}
			sum += num;

		}
		sum = sum - max;
		if(max-sum<=1 || max<=sum)
		{
			printf("%s\n", "Yes");
		}
		else
		{
			printf("%s\n", "No");
		}

	}
	return 0;
}