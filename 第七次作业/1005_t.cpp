/*
* @Author: TD21forever
* @Date:   2018-12-01 01:22:59
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-12-01 02:53:43
*/
#include<iostream>
#include<map>
#include<string>
#include <cstring>

using namespace std;
map<string, int> mp;
char s[100];
int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d", &n) == 1)
	{
		mp.clear();//放在循环里面

		for (int i = 1; i <= n; ++i)
		{
			scanf("%s", s);
			mp[s] = 0;
		}
		map<string, int>::iterator it;

		int days;
		scanf("%d", &days);
		while(days--)
		{
			for (int i = 1; i <= n; ++i)
			{
				int x;
				scanf("%d%s", &x, s);
				mp[s] += x;
			}
			int k = 0;
			for (it = mp.begin(); it != mp.end(); it++)
			{
				if (it->second > mp["memory"])
				{
					k++;
				}
			}
			printf("%d\n", ++k);
		}

	}
	return 0;
}