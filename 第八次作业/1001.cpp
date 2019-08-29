/*
* @Author: TD21forever
* @Date:   2018-12-04 09:25:44
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-12-04 20:47:14
*/

#include<iostream>
#include<string.h>
using namespace std;
int value[1005];
int waste[1005];
int B[1005][1005];

/*
1
5 0
2 4 1 5 1
0 0 1 0 0
背包容量为零也可以
*/

int main(int argc, char const *argv[])
{

	int t;
	scanf("%d", &t);
	while(t--)
	{
		memset(value, 0, sizeof(value));
		memset(waste, 0, sizeof(waste));
		memset(B, 0, sizeof(B));

		int num;
		int volume;
		scanf("%d %d", &num, &volume);
		for (int i = 1; i <= num; ++i)
		{
			scanf("%d", &value[i]);
		}
		for (int i = 1; i <= num; ++i)
		{
			scanf("%d", &waste[i]);
		}
		for (int now = 1; now <= num; ++now)
		{
			for (int capacity = 0; capacity <= volume; ++capacity)
			{
				if (capacity < waste[now])
				{
					B[now][capacity] = B[now - 1][capacity];
				}
				else
				{
					int temp1 = B[now - 1][capacity];//不拿
					int temp2 = B[now - 1][capacity - waste[now]] + value[now];//拿
					if (temp1 > temp2)
					{
						B[now][capacity] = temp1;
					}
					else
					{
						B[now][capacity] = temp2;
					}

				}
			}
		}
		printf("%d\n", B[num][volume]);

	}
	return 0;
}