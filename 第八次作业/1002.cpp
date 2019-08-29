/*
* @Author: TD21forever
* @Date:   2018-12-05 18:41:40
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-12-05 19:14:49
*/
#include<iostream>
#include<string.h>

using namespace std;
int waste[505] = {};
int value[505] = {};
int dp[10005] = {};
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int e;
		int f;
		memset(waste, 0, sizeof(waste));
		memset(value, 0, sizeof(value));
		scanf("%d %d", &e, &f);
		int capacity = f - e;
		dp[0] = 0;//dp[0]表示什么也不装 最小价值为0
		for (int i = 1; i <= capacity + 2; ++i)
		{
			dp[i] = 999999999;//初始化
		}
		int n;//n种类型
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d %d", &value[i], &waste[i]);
		}

		for (int i = 1; i <= n; ++i)
		{
			for (int j = waste[i]; j <= capacity; ++j)
			{
				dp[j] = min(dp[j], dp[j - waste[i]] + value[i]);
			}
		}
		if (dp[capacity] == 999999999)
		{
			printf("This is impossible.\n");
		}
		else
		{
			printf("The minimum amount of money in the piggy-bank is %d.\n",dp[capacity]);

		}
	}
	return 0;
}