/*
* @Author: TD21forever
* @Date:   2018-09-20 22:45:52
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-09-20 23:05:34
*/
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	int grades;
	while(scanf("%d", &grades)==1)
	{
		if(grades>100||grades<0)
		{
			printf("%s\n", "Score is error!");
			continue;
		}
		grades /= 10;
		if(grades < 5)
		{
			grades = 5;
		}
		switch(grades)
		{
		case 10:
		case 9: printf("%s\n", "A");break;
		case 8: printf("%s\n", "B");break;
		case 7: printf("%s\n", "C");break;
		case 6: printf("%s\n", "D");break;
		case 5: printf("%s\n", "E");break;
		default:break;
		}
	}
	return 0;
}