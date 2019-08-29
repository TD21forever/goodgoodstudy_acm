/*
* @Author: TD21forever
* @Date:   2018-10-28 23:52:51
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-10-29 20:31:28
*/
#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#define INF 99999999
int arr[111][111];
int opt[21][11];
int ans;
int min(int a, int b)
{
	return a < b ? a : b;
}
int main(int argc, char const *argv[])
{
	int n, k;
	int res;
	while(scanf("%d %d", &n, &k) == 2)
	{
		ans = 99999999;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < k ; ++j)
			{
				scanf("%d", &arr[i][j]);
			}
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < k; ++j)
			{
				opt[i][j] = INF;
			}
		}
		for (int i = 0; i < k; ++i)
		{
			opt[0][i] = 0;
		}
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < k; ++j)
			{

				for (int p = 0; p < k; ++p)
				{
					//思路一
					// res = opt[i - 1][j] + abs(arr[i - 1][j] - arr[i][p]);
					// if (res < opt[i][j])
					// {
					// 	opt[i][j] = res;
					// }
					//思路二
					opt[i][j] = min(opt[i][j],opt[i-1][j]+abs(arr[i-1][j]-arr[i][p]));
				}
			}
		}

		// for (int i = 0; i < n; ++i)
		// {
		// 	for (int j = 0; j < k; ++j)
		// 	{
		// 		printf("%d\n", opt[i][j]);
		// 	}
		// }
		for(int i=0;i<k;i++)
			if(ans>opt[n-1][i]) ans=opt[n-1][i];
		printf("%d\n",ans);
	}



	return 0;
}