/*
* @Author: TD21forever
* @Date:   2019-01-03 16:25:15
* @Last Modified by:   TD21forever
* @Last Modified time: 2019-01-03 16:37:40
*/
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	int a1, b1, c1;
	int a2, b2, c2;
	int a3, b3, c3;

	scanf("%d", &n);
	while(n--)
	{
		int flag = 0;
		int flag2 = 0;
		scanf("%d %d %d %d %d %d", &a1, &b1, &c1, &a2, &b2, &c2);
		c3 = c1 + c2;
		if(c3 >= 60)
		{
			flag = 1;
			c3 -= 60;
		}
		b3 = b1 + b2;
		if (flag)
		{
			b3 += 1;
		}
		if(b3 >= 60)
		{
			flag2 = 1;
			b3 -= 60;
		}
		a3 = a1 + a2;
		if (flag2)
		{
			a3 += 1;
		}
		printf("%d %d %d\n", a3, b3, c3);

	}
	return 0;
}