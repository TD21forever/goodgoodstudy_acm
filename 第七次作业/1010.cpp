/*
* @Author: TD21forever
* @Date:   2018-11-17 01:57:42
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-11-17 14:09:22
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int n, m, t, di, dj, si, sj;
char Map[9][9];
bool escape;
int direction[4][2] =
{
	{0, -1}, {0, 1}, {1, 0}, {-1, 0}
};
void dfs(int si, int sj, int cnt); //当前的位置，和用掉的时间
int main(int argc, char const *argv[])
{
	int i, j;
	while(scanf("%d %d %d", &n, &m, &t) == 3)
	{
		if (n == 0 && m == 0 && t == 0)
		{
			break;
		}
		int wall = 0;
		// char ch = getchar();
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= m; j++)
			{

				cin>>Map[i][j];
				if (Map[i][j] == 'S')
				{
					si = i;
					sj = j;
				}
				else if (Map[i][j] == 'D')
				{
					di = i;
					dj = j;
				}
				else if(Map[i][j] == 'X')
				{
					wall++;
				}
			}
			// ch = getchar();

		}

		if (n * m - wall <= t) // 我把地图上每个位置都走遍了门还没开
		{
			printf("NO\n");
			continue;
		}
		escape = 0;
		Map[si][sj] = 'X';
		dfs(si, sj, 0);
		if (escape)
		{
			cout << "YES" << endl;

		}
		else
			cout << "NO" << endl;
	}
	return 0;
}

void dfs(int si, int sj, int cnt)
{
	int  temp;
	if (si > n || sj > m || si <= 0 || sj <= 0)
	{
		return;
	}
	if (cnt == t && si == di && sj == dj)
	{
		escape = 1;
	}
	if (escape)
	{
		return;
	}
	//剪枝
	temp = (t - cnt) - abs(si - di) - abs(sj - dj); //剩下的时间 和 最短路径
	if (temp < 0 || temp % 2 == 1) //剩下的时间比最短路径消耗的时间还少 赶不到了   and  奇偶性剪枝 temp一定是偶数
	{
		//如果最短路径是奇数 那么剩下的时间必须是奇数 奇数-奇数=偶数
		//如果最短路径是偶数 那么剩下的时间必须是偶数 偶数-偶数=偶数
		//所以不管怎么样 temp 都是偶数
		return;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (Map[si + direction[i][0]][sj + direction[i][1]] != 'X')
		{
			Map[si + direction[i][0]][sj + direction[i][1]] = 'X';
			dfs(si + direction[i][0], sj + direction[i][1], cnt + 1);
			Map[si + direction[i][0]][sj + direction[i][1]] = '.';
		}
	}



}