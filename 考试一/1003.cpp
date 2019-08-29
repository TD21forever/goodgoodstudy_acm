/*
* @Author: TD21forever
* @Date:   2018-12-20 18:49:58
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-12-20 19:15:13
*/
#include<bits/stdc++.h>
using namespace std;

int arr[] = {2,3,5,7};
int main(int argc, char const *argv[])
{
	long long int n;
	while(scanf("%lld",&n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		long long res = 1;
		for (int i = 0; i < 4; ++i)
		{
			int cnt = 1;
			while(n%arr[i] == 0)
			{
				n/=arr[i];
				cnt++;
			}
			res*=cnt;
		}
		printf("%lld\n", res);
	}
	return 0;
}