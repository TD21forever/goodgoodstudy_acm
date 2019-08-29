/*
* @Author: TD21forever
* @Date:   2018-12-20 19:09:29
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-12-20 19:47:11
*/
#include<bits/stdc++.h>
using namespace std;

int arr[55];
int arrborn[55];
int main(int argc, char const *argv[])
{
	arrborn[0] = 0;
	arrborn[1] = 1;
	arrborn[2] = 0;
	arrborn[3] = 4;
	arrborn[4] = 4;
	int t;
	scanf("%d",&t);
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 5;
	arr[4] = 9;
	for (int i = 5; i <= 55; ++i)
	{
		arrborn[i] = (arrborn[i-2]+arrborn[i-3]+arrborn[i-4])*4;
		arr[i] = arr[i-1] + arrborn[i] - arrborn[i-5];
	}
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",arr[n]);
	}

	return 0;
}