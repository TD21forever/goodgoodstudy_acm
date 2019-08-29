/*
* @Author: TD21forever
* @Date:   2018-12-05 00:32:51
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-12-05 19:38:48
*/
//一维数组的解法

#include<iostream>
#include<string.h>
#include <algorithm>
using namespace std;

int value[1005];
int waste[1005];
int B[1005];

/*
1
5 0
2 4 1 5 1
0 0 1 0 0
背包容量为零也可以
*/

int max(int a,int b)
{
	return a<b?b:a;
}

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
			for (int capacity = volume; capacity >= waste[now]; --capacity)
			{//如何理解capacity >= waste[now]？ 因为当前的容量肯定要比所消耗的容量大 你才去考虑拿不拿这个物品 对吧 比如容量是10 当前这个物品消耗4 
				//你只要考虑6-10的就好了
				B[capacity] = max(B[capacity],B[capacity-waste[now]]+value[now]);
			}
		}
		printf("%d\n", B[volume]);

	}
	return 0;
}