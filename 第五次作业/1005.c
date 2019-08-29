/*
* @Author: TD21forever
* @Date:   2018-10-20 12:56:17
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-10-26 16:48:01
*/

//第三个数怎么求 其实就是前两个数 每个数分别乘2 3 5 7 然后得到最小值 并且这个最小值要比第二个数大 保证他是上升的 但这样复杂度会很高 因为会有很多重复的运算
#include<stdio.h>
#include<stdlib.h>
int min(int a, int b)
{
	return a <= b ? a : b;

}
int main(int argc, char const *argv[])
{
	int a[6000];
	a[1] = 1;
	int pos1 = 1;
	int pos2 = 1;
	int pos3 = 1;
	int pos4 = 1;

	for(int i = 2; i < 6000; i++)
	{
		a[i] = min(min(a[pos1] * 2, a[pos2] * 3), min(a[pos3] * 5, a[pos4] * 7));

		if (a[pos1] * 2 == a[i])
		{
			pos1++;
		}

		if (a[pos2] * 3 == a[i])
		{
			pos2++;
		}

		if (a[pos3] * 5 == a[i])
		{
			pos3++;
		}

		if (a[pos4] * 7 == a[i])
		{
			pos4++;
		}
	}


	int n;

	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		if (n % 10 == 1 && n % 100 != 11)
			printf("The %dst humble number is ", n);
		else if (n % 10 == 2 && n % 100 != 12)
			printf("The %dnd humble number is ", n);
		else if (n % 10 == 3 && n % 100 != 13)
			printf("The %drd humble number is ", n);
		else
			printf("The %dth humble number is ", n);

		printf("%d.\n", a[n]);

	}

	return 0;
}