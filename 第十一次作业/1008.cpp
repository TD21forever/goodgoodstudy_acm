/*
* @Author: TD21forever
* @Date:   2018-12-14 02:40:06
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-12-14 12:50:27
*/
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m)&&n&&m)
	{
		if(n%2&&m%2)
			printf("What a pity!\n");
		else
			printf("Wonderful!\n");
	}
	return 0;
}

/*罗列出先手的人赢的棋局
1,1*1输
2.2*1赢，1*2赢
3.2*2赢，2*3赢，3*2赢
4.3*3输
综上述，先手只要棋盘不是奇数乘奇数就能赢

*/
