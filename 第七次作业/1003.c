/*
* @Author: TD21forever
* @Date:   2018-11-16 00:42:28
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-11-16 21:58:02
*/
/*
 3
 4     题意：
 5         开始表示看不懂，后来才知道是给出n块pie，和f+1个人，要求没个人只能拿一块，
 6     可以是完整的一块也可以是不完整的一块。不一定要用上全部的pie。
 7
 8     二分法：
 9         奇葩的题...
10         假设 x 为每个人在限制条件下能得到的最大的体积的pie，有：
11
12             s[1]/x+s[2]/x+...+s[n]/x=f+1  //s[i]为第i块pie体积
13
14         然后再使用二分法求x，其中low=0，up=max{s[1],s[2],...,s[n]}
15
16 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define pi acos(-1.0)
int n;
int f;
double s[10010];
double max;
double mid;
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &f);
		int r;
		double max = 0.0;
		double right = 0.0,left = 0.0,mid;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &r);
			s[i] = pi * r * r;
			right += s[i];
		}
		right/=(f+1);

		printf("%.4lf\n",max-right);
		while((right - left) > 1e-7)
		{

			int sum = 0;
			mid = (right + left) / 2.0;

			for (int i = 0; i < n; ++i)
			{
				// printf("第%d快 %d\n",i+1,(int)(s[i]/mid));
				sum += (int)(s[i] / mid);//如果每个人分到mid这么大的pie 那么一共可以分给几个人
			}
			// printf("%d\n", sum);
			if (sum >= (f + 1))//如果分的太多了 说明每一块pie的面积太小了 哪怕是到了符合要求的人数 也看下能不能再大一点
			{
				left = mid;
			}
			else
			{
				right = mid;
			}
		}
		printf("%.4lf\n", mid);

	}
	return 0;
}

