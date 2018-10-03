/*
* @Author: TD21forever
* @Date:   2018-10-02 12:15:36
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-10-03 08:31:26
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int deadline;
	int score;
} List;

int cmp(const void *a, const void *b)
{
	return ((List *)b)->score - ((List *)a)->score;
}

int main(int argc, char const *argv[])
{
	List l[1005];
	int t, ans = 0;
	scanf("%d", &t);
	while(t--)
	{
		int mark[1000] = {};
		// printf("%d\n", mark[0]);
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &l[i].deadline);
		}

		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &l[i].score);
		}
		qsort(l, n, sizeof(List), cmp);
		for (int i = 0; i < n; ++i)
		{
			int j = l[i].deadline;
			// printf("%d\n", j);
			for (; j >= 1; --j)
			{
				// printf("%d\n", j);

				if(mark[j] == 0)
				{
					// printf("%d\n", mark[j] );
					mark[j] = 1;
					break;
				}
			}
			if (j == 0)
			{
				ans += l[i].score;
			}
		}
		printf("%d\n", ans);

		ans = 0;

	}

	return 0;
}