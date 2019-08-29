/*
* @Author: TD21forever
* @Date:   2018-12-14 01:41:36
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-12-14 02:39:07
*/
#include<iostream>
#include<string.h>
using namespace std;

#define P 0
#define N 1



int array[1050];

int main(int argc, char const *argv[])
{
	int c;
	scanf("%d", &c);
	while(c--)
	{
		memset(array, 0, sizeof(array));
		int total;
		int take;
		scanf("%d%d", &total, &take);
		int flag = 0;
		for (int i = 1; i <= total; ++i)
		{
			for (int j = 1; j <= take; ++j)
			{
				if (i - j >= 0 )
				{
					if (array[i - j] == P)//只要找到一个P
					{
						flag = 1;
						array[i] = N;
						break;
					}
					
				}
				else
				{
					break;
				}
				if (!flag)//没有找到P
				{
					array[i] = P;
				}
			}
		
		}
		if (array[total] == N)printf("first\n");
		else printf("second\n");



	}
	return 0;
}