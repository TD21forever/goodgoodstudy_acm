/*
* @Author: TD21forever
* @Date:   2018-09-28 20:58:31
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-09-28 23:48:21
*/

//Number Sequence
#include<stdio.h>
#include<stdlib.h>


int main(int argc, char const *argv[])
{
	long int a, b, i, temp, n;
	while(scanf("%ld %ld %ld", &a, &b, &n) == 3)
	{
		int array[50] = {};
		array[1] = 1;
		array[2] = 1;
		temp = 0;
		if(a == 0 && b == 0 && n == 0)
		{
			break;
		}

		for (i = 3; i < 50; ++i)
		{
			array[i] = (a * array[i - 1] + b * array[i - 2]) % 7;

			if(array[i] == array[i - 1] && array[i] == 1)// 很重要
			{

				break;
			}
		}
		temp = i - 2;
		printf("temp is %ld\n", temp);
		n = n % temp;
		array[0] = array[temp];
		printf("%d\n", array[n] );

	}

	return 0;
}