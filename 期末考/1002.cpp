#include<bits/stdc++.h>
using namespace std;
struct student
{
	char name[20];
	double grades;
	int age;
} a[1005];
bool cmp(student x, student y)
{
	if(x.grades > y.grades)
		return 1;
	else if(x.grades == y.grades)
	{
		if(x.age < y.age)
			return 1;
		else if(x.age == y.age)
		{
			if(strcmp(x.name, y.name) < 0)
				return 1;
		}
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d", &n) == 1)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%s %d %lf", a[i].name,&a[i].age,&a[i].grades);
		}
		sort(a, a + n, cmp);
		for(int i = 0; i < n; i++)
		{
			printf("%s %d %.2lf\n", a[i].name,a[i].age,a[i].grades);
		}
	}

	return 0;
}