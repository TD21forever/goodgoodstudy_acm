/*
* @Author: TD21forever
* @Date:   2018-11-15 22:58:38
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-11-16 00:15:49
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int t;
double mid, ans, y;
double equation(double x)
{
	return (8 * x * x * x * x + 7 * x * x * x + 2 * x * x + 3 * x + 6);
}
int main(int argc, char const *argv[])
{

	scanf("%d", &t);
	while(t--)
	{
		double left = 0;
		double right = 100;//x的范围一定是在0-100
		scanf("%lf", &y);
		if (equation(0) <= y && y <= equation(100)) //Fx单调的 y应该在x的定义域对应的值域区间内
		{
			while((right - left) > 1e-8)
			{
				mid = (left + right) / 2;
				if (equation(mid) > y)  // 缩小区间
				{
					right = mid;
				}
				else
				{
					left = mid;
				}
			}
			printf("%.4lf\n", mid);//
		}
		else
		{
			printf("No solution!\n");
		}

	}
	return 0;
}