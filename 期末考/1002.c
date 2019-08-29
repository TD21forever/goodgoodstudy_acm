/*
* @Author: TD21forever
* @Date:   2019-01-03 19:07:21
* @Last Modified by:   TD21forever
* @Last Modified time: 2019-01-03 19:19:00
*/
#include<stdio.h>
#include<stdlib.h>


typedef struct
{
	char  name[20];
	int age;
	double grades;
} student;

int cmp(const void *a, const void *b)
{
	stu c = *(stu *)a;
	stu d = *(stu *)b;
	if (c.grades > d.grades)
	{
		return c.grades - d.grades;
	}
	else
	{
		if(strcmp(c.name, d.name) == 0)
		{
			return c.id - d.id;
		}

		else
		{
			if(strcmp(c.name, d.name) > 0)
			{
				return strcmp(c.name, d.name);
			}
		}
	}

}

int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d", n))
	{
		for (int i = 1; i <= n; ++i)
		{

		}
	}

	return 0;
}