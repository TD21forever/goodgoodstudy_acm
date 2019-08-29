/*
* @Author: TD21forever
* @Date:   2018-11-28 13:56:18
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-11-28 14:32:56
*/
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

int startx, starty, endx, endy;

struct Node
{
	int x;
	int y;
	int step;
};

int dir[8][2] =
{
	{1,-2},
	{2,-1},
	{2,1},
	{1,2},
	{-1,2},
	{-2,1},
	{-2,-1},
	{-1,-2},
};

int visit[9][9];

int BFS()
{
	memset(visit,0,sizeof(visit));
	queue<Node> q;
	Node cur, next;
	cur.x = startx;
	cur.y = starty;
	cur.step = 0;
	visit[cur.x][cur.y] = 1;
	q.push(cur);
	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		if (cur.x == endx && cur.y == endy)
		{
			return cur.step;
		}

		for (int i = 0; i < 8; ++i)
		{
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			if (next.x >= 1 && next.x <= 8 && next.y >= 1 && next.y <= 8 && visit[next.x][next.y] == 0 )
			{
				visit[next.x][next.y] = 1;
				next.step = cur.step+1;//这里老是写错
				q.push(next);
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
		startx = start[0] - 'a' + 1;
		starty = start[1] - '1' + 1;
		endx = end[0] - 'a' + 1;
		endy = end[1] - '1' + 1;

		int n = BFS();
		printf("To get from %s to %s takes %d knight moves.\n", start, end, n);
	}	
	return 0;
}