/*
* @Author: TD21forever
* @Date:   2018-09-28 00:50:58
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-09-28 23:48:08
*/

//个位数

#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	int t, n, temp, p;
	scanf("%d", &t);
	int a[5] = {6, 2, 4, 8, 6};
	int b[5] = {1, 3, 9, 7, 1};
	int c[5] = {1, 7, 9, 3, 1};

			   while(t--)
	{
		scanf("%d", &n);
		temp = n;
		n = n % 10;
		if(n == 0) printf("%d\n", 0);
		if(n == 1) printf("%d\n", 1);
		if(n == 5) printf("%d\n", 5);
		if(n == 6) printf("%d\n", 6);
		if(n == 8)
		{
			p = (3 * temp) % 4;
			printf("%d\n", a[p]);
		}
		if(n == 4)
		{
			p = (2 * temp) % 4;
			printf("%d\n", a[p]);
		}
		if(n == 2)
		{
			p = (1 * temp) % 4;
			printf("%d\n", a[p]);
		}
		if(n == 3)
		{
			p = temp % 4;
			printf("%d\n", b[p]);
		}
		if(n==9)
		{
			p = (2*temp) % 4;
			printf("%d\n", b[p]);
		}
		if(n==7)
		{
			p = (1*temp) % 4;
			printf("%d\n", c[p]);
		}

	}
	return 0;
}