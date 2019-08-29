/*
* @Author: TD21forever
* @Date:   2018-10-20 11:33:14
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-10-23 20:56:48
*/
#include<stdio.h>
#include<stdlib.h>
long long max(long long a, long long b)
{
	int res;
	if (a > b)
	{
		res = a;
	}
	else
	{
		res = b;

	}
	return res;
}
int main(int argc, char const *argv[])
{
	int n;

	while(scanf("%d", &n) == 1)
	{
		long long arr[1001] = {};
		long long pre[1001] = {};
		if (n == 0)
		{
			break;
		}
		for (int i = 1; i <= n; ++i)
		{
			long long num;
			scanf("%I64d", &num);
			arr[i] = num;
		}
		arr[0] = 0;
		int flag = 1;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = i; j >= 1; j--)
			{
				if (arr[i] > arr[j] && arr[j] != 0 )
				{
					flag = 0;
					pre[i] = j;
					break;

				}
			}
			if (flag)
			{
				pre[i] = 0;
			}
		}
		long long opt[1001] = {};
		opt[1] = arr[1];
		opt[0] = -2147483647;
		for (int i = 1; i <= n; i++)
		{
			if(arr[i] == 0 )
			{
				opt[i] = 0;
			}
			else
			{

				opt[i] = max(opt[i - 1], opt[pre[i]] + arr[i]);
			}
		}
		long long res = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (res < opt[i])
			{
				res = opt[i];
			}

		}
		// for (int i = 1; i <= n; ++i)
		// {
		// 	printf("%I64d",opt[i]);
		// }

		printf("%I64d\n", res);

	}
	return 0;
}