/*
* @Author: TD21forever
* @Date:   2018-12-05 14:54:22
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-12-05 15:28:49
*/


#include<iostream>
#include<string.h>
using namespace std;

int waste[4] = {0, 150, 200, 350};
int value[4] = {0, 150, 200, 350};
int dp[10005] = {};
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int money;
		scanf("%d", &money);
		for (int i = 1; i <= 3 ; ++i)
		{
			for (int j = waste[i]; j <= money; ++j)
			{
				dp[j] = max(dp[j], dp[j - waste[i]] + value[i]);
			}
		}
		printf("%d\n", money - dp[money]);
	}
	return 0;
}