/*
* @Author: TD21forever
* @Date:   2018-11-16 00:09:05
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-11-16 01:02:49
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int t;
double mid, ans, y;
double equation(double x)
{
	return (42 * pow(x, 6.0) + 48 * pow(x, 5.0) + 21 * pow(x, 2.0) + 10 * x);//最小值 即导函数等于0 这里是fx = y
}
double result(double x,double y)
{
	return (6 * pow(x, 7.0) + 8 * pow(x, 6.0) + 7 * pow(x, 3.0) + 5 * x * x - y * x);
}
int main(int argc, char const *argv[])
{

	scanf("%d", &t);
	while(t--)
	{
		double left = 0;
		double right = 100;//x的范围一定是在0-100
		scanf("%lf", &y);

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
		printf("%.4lf\n", result(mid,y));


	}
	return 0;
}