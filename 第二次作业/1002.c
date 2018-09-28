/*
* @Author: DESKTOP-0VVB0MB$
* @Date:   2018-09-27 21:01:07
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-09-28 23:17:47
*/
#include<stdio.h>
#include<stdlib.h>

//Elevator

int main(int argc, char const *argv[])
{
	int N, total = 0, i, level, last_level = 0;
	while(scanf("%d", &N) == 1)
	{
		if(N == 0)
		{
			break;
		}
		for (i = 0; i < N; ++i)
		{
			scanf("%d", &level);
			if(level < last_level)
			{
				total += (last_level - level) * 4;  //注意在原来的基础上
			}
			else
			{
				total += (level - last_level) * 6;

			}
			last_level = level;

		}
		total += N * 5; //有n个人就加n*5秒
		printf("%d\n", total);
		total = 0;
		last_level = 0;

	}
	return 0;
}