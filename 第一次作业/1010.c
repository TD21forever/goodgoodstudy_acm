/*
* @Author: TD21forever
* @Date:   2018-09-20 22:35:16
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-09-20 22:43:38
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char const *argv[])
{
	double x1,y1,x2,y2;
	double distance = 0.0;
	while(scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2)==4)
	{
		distance = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		printf("%.2lf\n", distance);
	}

	return 0;
}