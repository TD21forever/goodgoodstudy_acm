/*
* @Author: TD21forever
* @Date:   2018-12-20 18:40:56
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-12-20 18:49:07
*/
#include<bits/stdc++.h>
using namespace std;


int get_num(char *s)
{
	char a[50] ;
	strcpy(a,s);
	int cnt_int = 0;
	for(int i = 0; a[i] != '\0'; ++i) 
	{
		if(a[i] >= '0' && a[i] <= '9') 
		{
			cnt_int *= 10;
			cnt_int += a[i] - '0'; 
		}
	}


	return cnt_int;
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);

	while(n--)
	{
		char arr[40];
		scanf("%s",arr);
		int a = get_num(arr);
		printf("%d\n", a*513);		
	}
	
	return 0;
}