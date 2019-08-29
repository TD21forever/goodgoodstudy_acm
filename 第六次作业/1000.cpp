/*
* @Author: TD21forever
* @Date:   2018-11-02 20:20:33
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-11-03 15:46:03
*/
#include<iostream>
#include<queue>
using namespace std; 
//按照题目要求 定义全局变量
int n;
int start_level;
int END_LEVEL;
//lift_info 存入的是每一层的up或down的值
int lift_info[202];
//vis_lift 存入是否访问过这一层
int vis_lift[202];
//一个结构体储存当前这一层的信息，当前是第几层，到当前这一层用了几步
struct level_info
{	
	int level;
	int step;
};
void bfs()
{
	level_info cur,next;
	queue<level_info>qu;
	//当前在开始这层
	cur.level = start_level;
	//这层访问过了
	vis_lift[cur.level] = 1;
	cur.step = 0;
	//放到队列里
	qu.push(cur);
	while(!qu.empty())
	{
		cur = qu.front();
		qu.pop();
		if (cur.level == END_LEVEL)
		{
			printf("%d\n", cur.step);
			return;
		}
//下一层可以是上去
		next.level = cur.level+lift_info[cur.level];
		next.step = cur.step+1;
		if (next.level <= n)
		{
			if (vis_lift[next.level] == 0)
			{
				vis_lift[next.level] = 1;
				qu.push(next);
			}
		}
//下一层可以是下去
		next.level = cur.level-lift_info[cur.level];
		next.step = cur.step+1;
		if (next.level >= 1)
		{
			if (vis_lift[next.level] == 0)//剪枝，没访问过才去访问他
			{
				vis_lift[next.level] = 1;
				qu.push(next);
			}
		}
	}
	printf("-1\n");
	return;
}
int main(int argc, char const *argv[])
{
	while(scanf("%d",&n)==1)
	{
		if(n==0)
		{
			break;
		}
		scanf("%d %d",&start_level,&END_LEVEL);
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d",&lift_info[i]);
			vis_lift[i] = 0;
		}
		bfs();
	}
	
	
	return 0;
}
