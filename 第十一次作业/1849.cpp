/*
* @Author: TD21forever
* @Date:   2018-12-14 16:11:09
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-12-14 16:24:50
*/
#include<iostream>
#include<string.h>
using namespace std;

#define P 0
#define N 1
int arr[10020];

int main(int argc, char const *argv[])
{
	int num;

	while(scanf("%d", &num) == 1)
	{
		if (num == 0)
		{
			break;
		}
		int ans = 0;//0和别人异或都等于别人
		for (int i = 1; i <= num; ++i)
		{
			scanf("%d", &arr[i]);
			ans ^= arr[i];
		}
		if(ans)
			cout << "Rabbit Win!" << endl;
		else
			cout << "Grass Win!" << endl;
	}
	return 0;
}