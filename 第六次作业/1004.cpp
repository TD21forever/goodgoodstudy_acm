/*
* @Author: TD21forever
* @Date:   2018-11-28 14:46:42
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-11-28 16:24:52
*/

//一开始写的时候思路就不清楚 导致一些细节没有做好

//求有多少可以走的路
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int row, col;
int startx, starty;
char map[25][25];
int dir[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
int ans;
struct Node
{
	int x;
	int y;
};
int BFS()
{
	queue<Node>q;
	Node cur, next;
	cur.x = startx;
	cur.y = starty;
	q.push(cur);
	while(!q.empty())
	{
		cur = q.front();
		q.pop();//队列里的数量就是能走的路的数量
		map[cur.x][cur.y] = '#';
		ans++;

		for (int i = 0; i < 4 ; ++i)
		{
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];

			if (next.x >= 0 && next.x < row && next.y >= 0 && next.y < col && map[next.x][next.y] != '#')
			{//这里<row是没有等号的 错了好久  看一下有没有办法 以后别错了

				map[next.x][next.y] = '#';
				q.push(next);
			}
		}

	}
	return ans;
}

int main(int argc, char const *argv[])
{
	while(scanf("%d %d", &col, &row) == 2)
	{
		if (row == 0 && col == 0)
		{
			break;
		}
		for (int i = 0; i < row; i++)
		{
			scanf("%s", map[i]);
		}
		for (int i = 0; i < row ; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (map[i][j] == '@')
				{
					startx = i;
					starty = j;
				}
			}
		}
		ans = 0;
		int res = BFS();
		printf("%d\n", res);
	}
	return 0;
}