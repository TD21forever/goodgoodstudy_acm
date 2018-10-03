/*
* @Author: TD21forever
* @Date:   2018-09-29 22:42:57
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-09-29 23:48:08
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct TV   // 如果是一组数据进行排序 用结构体
{
	int start;
	int end;
} list;

int main(int argc, char const *argv[])
{
	list t[101];
	list temp;
	int i, n, j, sum;


	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		sum = 1;
		for (i = 0; i < n; ++i)
		{
			scanf("%d %d", &t[i].start, &t[i].end);
		}

		for (i = 0; i < n - 1; ++i) //一共n-1趟就好了
		{
			for ( j = 0; j < n - i - 1; ++j) //如4个数你要换3次 有i个数已经换好了
			{
				if(t[j].end > t[j + 1].end)   //升序
				{							//注意这里交换 是整个结构体数组交换
					temp = t[j];
					t[j] = t[j + 1];
					t[j + 1] = temp;
				}
			}
		}
		int index = 0;
		for (i = 1; i < n; ++i)
		{
			if(t[index].end <= t[i].start)
			{
				sum += 1;
				index = i;
			}
		}
		printf("%d\n", sum);

	}
	return 0;
}