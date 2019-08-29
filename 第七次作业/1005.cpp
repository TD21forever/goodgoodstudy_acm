/*
* @Author: TD21forever
* @Date:   2018-12-01 01:12:29
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-12-01 01:25:28
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#define  N 100005

using namespace std;
int n;
map<string, int>mp;
char s[100];

int main()
{
	// freopen("test.in","r",stdin);
	while(scanf("%d", &n) == 1)
	{
		mp.clear();
		for(int i = 1; i <= n; i++)//有n家商店
		{
			scanf("%s", s);
			mp[s] = 0;//初始化每一家商店的价格
		}
		map<string, int>::iterator it;
		int d;//天数	
		scanf("%d", &d);
		while(d--)
		{
			int x;
			for(int i = 1; i <= n; i++)
			{
				scanf("%d%s", &x, s);
				mp[s] += x;//价格每天都在涨
			}
			int k = 0;
			for(it = mp.begin(); it != mp.end(); it++)//把每一家商店都遍历一遍
			{
				if(it->second > mp["memory"])//it->second 得到int
				{
					k++;
				}
			}
			printf("%d\n", ++k);
		}
	}
}
