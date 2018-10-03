/*
* @Author: TD21forever
* @Date:   2018-09-30 21:01:25
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-09-30 23:27:28
*/
#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}
int main(int argc, char const *argv[])
{
	int t, num;
	scanf("%d", &t);
	int a[1001];
	while(t--)
	{
		int n, flag = 1;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &num);
			a[i] = num;
		}
		for (int i = 0; i < n; ++i)
		{
			qsort(a + i, n-i, sizeof(int), cmp);  //这里n-i指的是 从开始排序的点到结尾的长度
			if (a[n - 1] < 0)
			{
				flag = 0;
				printf("%s\n", "no");
				break;
			}
			for (int j = 1; j <= a[i]; ++j)  //做几次
			{
				--a[i+j];
			}
	
		}
		if (flag)
		{
			printf("%s\n", "yes");
		}
	}
	return 0;
}