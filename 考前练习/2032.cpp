/*
* @Author: TD21forever
* @Date:   2019-01-03 16:37:26
* @Last Modified by:   TD21forever
* @Last Modified time: 2019-01-03 20:43:22
*/
#include<bits/stdc++.h>
using namespace std;
int arr[35][35];

int main(int argc, char const *argv[])
{
	memset(arr, 0, sizeof(int));
	for (int i = 1; i <= 35; ++i)
	{
		arr[i][1] = 1;
		arr[i][i] = 1;
	}
	for (int i = 3; i <= 35; ++i)
	{
		for (int j = 2; j < i ; ++j)
		{
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
		}
	}
	int n;
	while(scanf("%d", &n) == 1)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= i; ++j)
			{
				if(j == i) printf("%d", arr[i][j]);
				else printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}