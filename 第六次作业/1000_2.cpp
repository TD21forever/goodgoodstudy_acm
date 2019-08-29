/*
* @Author: TD21forever
* @Date:   2018-11-02 18:28:45
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-11-02 20:41:54
*/
#include<bits/stdc++.h>
using namespace std;
int info[202];
int vis[202];
void bfs(int Start,int END);
int n;
struct pos
{
	int level;
	int step;
};

int main(int argc, char const *argv[])
{
	int Start, END;

	while(scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		scanf("%d%d", &Start, &END);
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &info[i]);
			vis[i] = 0;
		}
		bfs(Start,END);

	}
	return 0;
}
void bfs(int Start,int END)
{
	pos cur, next;
	cur.level = Start;
	cur.step = 0;
	queue<pos>qu;
	qu.push(cur);
	vis[Start] = 1;
	while(!qu.empty())
	{
		cur = qu.front();
		qu.pop();
		if (cur.level == END)
		{
			printf("%d\n", cur.step);
			return;
		}

		next.level = cur.level + info[cur.level];
		next.step = cur.step + 1;
		if (next.level <= n)
		{
			if (vis[next.level] == 0)
			{
				vis[next.level] = 1;
				qu.push(next);
			}
		}
		next.level = cur.level - info[cur.level];
		next.step = cur.step + 1;
		if (next.level >=1 )
		{
			if (vis[next.level] == 0)
			{
				vis[next.level] = 1;
				qu.push(next);
			}
		}

	}
	printf("-1\n");
	return;
}
