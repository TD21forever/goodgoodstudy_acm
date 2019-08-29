/*
* @Author: TD21forever
* @Date:   2018-12-05 15:46:04
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-12-05 16:20:40
*/
#include<iostream>
#include<string.h>
using namespace std;

int value[100005]={};
int waste[100005]={};
int dp[100005]={};
int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d", &n) == 1)
	{
		memset(value,0,sizeof(value));
		memset(waste,0,sizeof(waste));
		memset(dp,0,sizeof(dp));
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d %d", &value[i], &waste[i]);
		}
		int m;
		scanf("%d",&m);
		for (int i = 1; i <= n; ++i)
		{
			for (int j = waste[i]; j <= m; ++j)
			{
				dp[j] = max(dp[j],dp[j-waste[i]]+value[i]);
			}
		}
		printf("%d\n", dp[m]);

	}

	return 0;
}