/*
* @Author: TD21forever
* @Date:   2018-11-03 16:48:16
* @Last Modified by:   TD21forever
* @Last Modified visit: 2018-11-03 18:21:59
*/
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

int K;
int CENG, X, Y, TIME;
int next_ceng, next_x, next_y;
int maza_data[55][55][55];
int visit[55][55][55];

int start_x, start_y, start_ceng;
int change_x[6] = {1, 0, -1, 0, 0, 0};
int change_y[6] = {0, -1, 0, 1, 0, 0};
int change_ceng[6] = {0, 0, 0, 0, 1, -1};

struct position
{
	int ceng;
	int x;
	int y;
	int time;
};

int bfs()
{
	position now, next;
	memset(visit, 0, sizeof(visit));
	queue<position>qu;
	now.ceng = 0;
	now.x = 0;
	now.y = 0;
	now.time = 0;
	qu.push(now);
	visit[now.ceng][now.x][now.y] = 1;
	while(!qu.empty())
	{
		now = qu.front();
		qu.pop();

		if (now.ceng == CENG - 1 && now.x == X - 1 && now.y == Y - 1)
		{
			return now.time;
		}
		for (int i = 0; i < 6; ++i)
		{
			next.ceng = now.ceng + change_ceng[i];
			next.x = now.x + change_x[i];
			next.y = now.y + change_y[i];
			// if (next_ceng > CENG - 1 || next_ceng < 0 || next_x > X - 1 || next_x < 0 || next_y > Y - 1 || next_y < 0 || visit[next_ceng][next_x][next_y] != 0 || maza_data[next_ceng][next_x][next_y] != 0 || visit[next_ceng][next_x][next_y] > TIME)
			// {
			// 	continue;
			// }
			if (next.x >= 0 && next.x < X && next.y >= 0 && next.y < Y && next.ceng >= 0 && next.ceng < CENG)
			{
				if (visit[next.ceng][next.x][next.y] == 0 && maza_data[next.ceng][next.x][next.y] == 0)
				{
					visit[next.ceng][next.x][next.y] = 1;
					next.time  = now.time + 1;
					qu.push(next);
				}
			}
		}

	}
	return 999999;

}

int main(int argc, char const *argv[])
{

	scanf("%d", &K);
	while(K--)
	{
		scanf("%d %d %d %d", &CENG, &X, &Y, &TIME);
		for (int i = 0; i < CENG; ++i)
		{
			for (int j = 0; j < X; ++j)
			{
				for (int k = 0; k < Y; ++k)
				{
					scanf("%d", &maza_data[i][j][k]);
				}
			}
		}
		// if (maza_data[CENG - 1][X - 1][Y - 1] == 1)
		// {
		// 	printf("-1\n");
		// 	return 0;
		// }
		int ans = bfs();
		if (ans > TIME)
		{
			printf("-1\n");
		}
		else
		{

			printf("%d\n", ans);
		}
	}
	return 0;
}