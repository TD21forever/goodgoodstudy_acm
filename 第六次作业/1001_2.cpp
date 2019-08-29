/*
* @Author: TD21forever
* @Date:   2018-11-04 00:06:23
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-11-04 00:21:22
*/
#include <iostream>
#include <queue>
#include<string.h>
using namespace std;
int start_x, start_y, end_x, end_y;
//棋盘
int vis[9][9];
//可以跳八个方向
int change_x[8] = {1, -1, -2, -2, -1, 1, 2, 2};
int change_y[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
struct position
{
	int pos_x;
	int pos_y;
	int step;
};
int bfs()
{
	memset(vis, 0, sizeof(vis));
	position now,next;
	queue<position>qu;
	now.pos_x = start_x;
	now.pos_y = start_y;
	now.step = 0;
	vis[now.pos_x][now.pos_y] = 1;
	qu.push(now);
	while(!qu.empty())
	{
		now = qu.front();
		qu.pop();
		if (now.pos_x == end_x && now.pos_y == end_y)
		{
			return now.step;
		}
		for (int i = 0; i < 8; ++i)
		{
			next.pos_x = now.pos_x+change_x[i];
			next.pos_y = now.pos_y+change_y[i];
			//剪枝，别越界，访问的地方一定是以前没有访问过的
			// if (continue_x < 1 || continue_x > 8 || continue_y < 1 || continue_y > 8 || vis[continue_x][continue_y] != 0)
			// {
			// 	continue;
			// }
			if (next.pos_x>=1&&next.pos_x<=8&&next.pos_y>=1&&next.pos_y<=8&&vis[next.pos_x][next.pos_y]==0)
			{
				vis[next.pos_x][next.pos_y] = 1;
				next.step = now.step+1;
				qu.push(next);
			}
			
			

		}
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	char start[3];
	char end[3];
	while(scanf("%s %s", start, end) == 2)
	{
		start_x = start[0] - 'a' + 1;
		start_y = start[1] - '1' + 1;
		end_x = end[0] - 'a' + 1;
		end_y = end[1] - '1' + 1;

		int n = bfs();
		printf("To get from %s to %s takes %d knight moves.\n", start, end, n);
	}	
	return 0;
}