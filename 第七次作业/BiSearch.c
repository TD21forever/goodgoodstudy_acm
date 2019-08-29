/*
* @Author: TD21forever
* @Date:   2018-11-15 21:28:28
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-11-15 22:38:53
*/
#include<stdio.h>
#include<stdlib.h>
int BiSearch(int a[], int n, int num)
{
	int left = 0;
	int right = n - 1;
	while(left <= right)
	{
		int mid = (left + right) / 2;
		if (a[mid] == num)
		{
			return mid;
		}
		if (num < a[mid])
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return -1;

}

int bi_search(int a[], int num, int left, int right)
{

	if (left > right)
	{
		return -1;
	}
	else
	{
		int mid = (right + left) / 2;
		if (a[mid] == num)
		{
			return mid;
		}
		else if (num > a[mid])
		{
			return bi_search(a, num, mid + 1, right);
		}
		else
		{
			return bi_search(a, num, left, mid - 1);
		}

	}

}
int main(int argc, char const *argv[])
{
	int a[15]={2,4,6,7,8,12,14,15,17,20,27,28,29,33,34};
	int find_1=0;
	int find_2=0;
	find_1 = BiSearch(a,15,8);
	find_2 = bi_search(a,8,0,14);	
	printf("%d %d\n", find_1,find_2);
	return 0;
}