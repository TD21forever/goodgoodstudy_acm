/*
* @Author: TD21forever
* @Date:   2018-12-14 12:41:15
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-12-14 13:02:22
*/
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

#define P 0
#define N 1

int array[1050];

int main(int argc, char const *argv[])
{
	int total;
	while(scanf("%d",&total)==1)
	{	
		memset(array,0,sizeof(array));
		int flag = 0;
		array[0] = P;
		for (int i = 1; i <= total; ++i)
		{	
			for (int j = 0; j <= total; ++j)
			{
				if(i - int(pow(2,j))>=0)
				{
					int pos = i - int(pow(2,j));
					if (array[pos] == P)
					{
						flag = 1;
						array[i] = N;
						break;
					}
				}
				else break;
			}
			if (!flag)
			{
				array[i] = P;
			}
		}
	
		if (array[total] == N)
		{
			printf("Kiki\n");
		}
		else
		{
			printf("Cici\n");

		}
	}
	return 0;
}