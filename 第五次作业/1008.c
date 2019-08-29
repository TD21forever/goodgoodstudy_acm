/*
* @Author: TD21forever
* @Date:   2018-10-26 16:08:06
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-10-26 16:54:12
*/
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	int summax[100001];
	int sum[100001];
	// int head[100001];
	int tail[100001];
	// head[0] = 1;
	tail[0] = 1;


	while(t--)
	{
		int n;
		int temp = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			int num;
			scanf("%d", &num);
			temp += num;
			sum[i] = temp;
			summax[0] = sum[0];
			if (summax[i] < sum[i])
			{
				summax[i] = sum[i];
			}
			else
			{
				summax[i] = summax[i-1];
			}
			tail[i] = i + 1;

			if (sum[i] < 0)
			{
				sum[i] = 0;
				// head[i] = i + 1;
			}

		}

		for (int i = 0; i < n; ++i)
		{
			// printf("%d ", sum[i]);
			printf("\n");
			printf("%d", summax[i]);
			printf("\n");
			// printf("%d\n", head[i]);
			// printf("%d", tail[i]);

		}

	}
	return 0;
}