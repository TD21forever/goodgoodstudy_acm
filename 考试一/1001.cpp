/*
* @Author: TD21forever
* @Date:   2018-12-20 18:26:54
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-12-20 18:42:46
*/

#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int arr[1005];
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	memset(arr,0,sizeof(int));
	while(t--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&arr[i]);
		}
		sort(arr,arr+n,cmp);
		for (int i = 0; i < m; ++i)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	return 0;
}

/*
2
3 2
2 1 5
9 9
1 4 7 2 5 8 3 6 9
*/