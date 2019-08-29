#include<bits/stdc++.h>
using namespace std;

void fun(int a[], int n)
{

	while (1)
	{
		for(int i = 0; i < n; i++)
		{
			printf("%d ", a[i]); //当第一次进入循环时，就会输出一次从一开始就从小到大排列好的数
		}
		int j,k;
		printf("\n");
		for (j = n - 2; j >= 0 && a[j] > a[j + 1]; j--);  //这一步是从这一组数中右边(即从倒数第二个数判断，因为倒数第一个数右边没有数字）开始判断，找出第一个比自己右边数字小的数，下标存到j中

		if (j < 0) return;  
		for (k = n - 1; k > j && a[k] < a[j]; k--); 

		swap(a[k], a[j]);  //这是将上面找到第一个比左边数字小的数字j和数字j右边比j大的数字中最小的数字k互换一下，这是为了把还没排在前面过的数字，排到前面去

		for (int l = j + 1, r = n - 1; l < r; l++, r--)  //因为此时j这个位置的数字后面的数是从大到小排序的，给对调一下就得出了下一次要输出的全排列
			swap(a[l], a[r]);
	}
}


int arr[100];

int main()
{
	int n;
	while(scanf("%d", &n) == 1)
	{

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}
		sort(arr, arr + n);
		fun(arr, n);

	}

	return 0;
}
