/*
* @Author: TD21forever
* @Date:   2019-01-03 19:52:26
* @Last Modified by:   TD21forever
* @Last Modified time: 2019-01-03 20:32:43
*/
#include<bits/stdc++.h>
using namespace std;
int book[1005];
struct Reader
{
	int len;
	int need;
} reader[1005];

int main(int argc, char const *argv[])
{
	int n, m;

	while(scanf("%d %d", &n, &m) == 2)
	{
		for (int i = 0; i < 1005; ++i)
		{
			reader[i].len = 1;
		}
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &book[i]);
		}
		sort(book, book + n);
		for (int i = 0; i < m; ++i)
		{
			scanf("%d %d", &reader[i].len, &reader[i].need);
			int number = 1;
			for (int j = 0; j < reader[i].len; ++j)
			{
				number *= 10;
			}
			reader[i].len = number;
		}
		for (int i = 0; i < m; ++i)
		{
			int flag = 0;
			for (int k = 0; k < n; ++k)
			{
				if (book[k] == reader[i].need && flag == 0)
				{
					printf("%d\n", book[k]);
					flag = 1;
				}
				else
				{
					if (book[k] > reader[i].need)
					{
						if (book[k] % reader[i].len == reader[i].need && flag == 0 )
						{
							printf("%d\n", book[k]);
							flag = 1;
						}
					}
				}
			}
			if (!flag)
			{
				printf("-1\n");
			}
		}
	}
	return 0;
}


/*


5 5
2123
1123
23
24
24
2 23
3 123
3 124
2 12
2 12

*/