/*
* @Author: TD21forever
* @Date:   2019-01-03 18:27:09
* @Last Modified by:   TD21forever
* @Last Modified time: 2019-01-03 19:30:35
*/
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int a, b, c;
		scanf("%d %d %d",&a,&b,&c);
		if (a + b > c && a + c > b && b + c > a)//任意两边之和大于第三遍
		{
			if(a * a + b * b > c * c && a * a + c * c > b * b && b * b + c * c > a * a)
			{
				printf("Acute triangle\n");
			}
			else if(a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
			{
				printf("Right triangle\n");
			}
			else
			{
				printf("Obtuse triangle\n");
			}
		}
		else
		{
			printf("Impossible!\n");
		}
	}
	return 0;
}

