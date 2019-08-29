/*
* @Author: TD21forever
* @Date:   2018-11-05 20:37:21
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-11-08 00:41:32
*/
#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

int capacity_first, capacity_second, capacity_third;
int visit[120][120][120];
struct cup_info
{
	int first_cup;
	int second_cup;
	int third_cup;
	int step;
};

int bfs()
{
	memset(visit, 0, sizeof(visit));
	cup_info cur, next;
	cur.first_cup =  capacity_first;
	cur.second_cup = 0;
	cur.third_cup = 0;
	cur.step = 0;
	visit[cur.first_cup][cur.second_cup][cur.third_cup] = 1;
	queue<cup_info>qu;
	qu.push(cur);
	while(!qu.empty())
	{
		cur = qu.front();
		qu.pop();
		printf("%d %d %d\n", cur.first_cup, cur.second_cup, cur.third_cup);

		if ((cur.first_cup == capacity_first / 2 && cur.second_cup == capacity_first / 2) || (cur.first_cup == capacity_first / 2 && cur.third_cup == capacity_first / 2) || (cur.second_cup == capacity_first / 2 && cur.third_cup == capacity_first / 2))
		{
			printf("%d\n", cur.step);
			return cur.step;
		}

		//第一杯倒到第二杯里
		if (cur.first_cup != 0)
		{

			// if ((capacity_second - cur.second_cup) > cur.first_cup)
			// {
			// 	next.first_cup = 0;
			// 	next.second_cup = cur.second_cup + cur.first_cup;
			// }
			// else
			// {
			if(next.second_cup != capacity_second)
			{
				next.second_cup = capacity_second;
				next.first_cup = cur.first_cup -  (next.second_cup - cur.second_cup);
				// }

				next.third_cup = cur.third_cup;
				if (visit[next.first_cup][next.second_cup][next.third_cup] == 0 && next.first_cup <= capacity_first && next.second_cup <= capacity_second && next.third_cup <= capacity_third)
				{
					next.step = cur.step + 1;
					visit[next.first_cup][next.second_cup][next.third_cup] = 1;
					qu.push(next);
				}
			}

			//第一杯倒到第三杯里
			// if ((capacity_third - cur.third_cup) > cur.first_cup)
			// {
			// 	next.first_cup = 0;
			// 	next.third_cup = cur.third_cup + cur.first_cup;
			// }
			// else
			// {
			if(next.third_cup != capacity_third)
			{
				next.third_cup = capacity_third;
				next.first_cup = cur.first_cup -  (next.third_cup - cur.third_cup);
				// }
				next.second_cup = cur.third_cup;
				if (visit[next.first_cup][next.second_cup][next.third_cup] == 0 && next.first_cup <= capacity_first && next.second_cup <= capacity_second && next.third_cup <= capacity_third)
				{
					next.step = cur.step + 1;
					visit[next.first_cup][next.second_cup][next.third_cup] = 1;
					qu.push(next);
				}

			}
		}

		//第二杯倒到第一杯里
		if (cur.second_cup != 0)
		{
			next.second_cup = 0;
			next.first_cup = cur.first_cup + cur.second_cup;
			next.third_cup = cur.third_cup;
			if (visit[next.first_cup][next.second_cup][next.third_cup] == 0 && next.first_cup <= capacity_first && next.second_cup <= capacity_second && next.third_cup <= capacity_third)
			{
				next.step = cur.step + 1;
				visit[next.first_cup][next.second_cup][next.third_cup] = 1;
				qu.push(next);
			}

			//第二杯倒在第三杯里
			if ((capacity_third - cur.third_cup) > cur.second_cup)
			{
				next.second_cup = 0;
				next.third_cup = cur.third_cup + cur.second_cup;
			}
			else
			{
				next.third_cup = capacity_third;
				next.second_cup = cur.second_cup - (next.third_cup - cur.third_cup);
			}
			next.first_cup = cur.first_cup;
			if (visit[next.first_cup][next.second_cup][next.third_cup] == 0 && next.first_cup <= capacity_first && next.second_cup <= capacity_second && next.third_cup <= capacity_third)
			{
				next.step = cur.step + 1;
				visit[next.first_cup][next.second_cup][next.third_cup] = 1;
				qu.push(next);

			}
		}


		//第三杯倒在第一杯里

		if (cur.third_cup != 0)
		{
			next.third_cup = 0;
			next.first_cup = cur.first_cup + cur.third_cup;
			if (visit[next.first_cup][next.second_cup][next.third_cup] == 0 && next.first_cup <= capacity_first && next.second_cup <= capacity_second && next.third_cup <= capacity_third)
			{
				next.step = cur.step + 1;
				visit[next.first_cup][next.second_cup][next.third_cup] = 1;
				qu.push(next);
			}
			//第三杯倒在第二杯里
			if ((capacity_second - cur.second_cup) > cur.third_cup)
			{
				next.third_cup = 0;
				next.second_cup = next.second_cup + cur.third_cup;
			}
			else
			{
				next.second_cup = capacity_second;
				next.third_cup = cur.third_cup - (next.second_cup - cur.second_cup);
			}
			next.first_cup = cur.first_cup;
			if (visit[next.first_cup][next.second_cup][next.third_cup] == 0 && next.first_cup <= capacity_first && next.second_cup <= capacity_second && next.third_cup <= capacity_third)
			{
				next.step = cur.step + 1;
				visit[next.first_cup][next.second_cup][next.third_cup] = 1;
				qu.push(next);

			}
		}





	}
	printf("NO\n");
	return -1;
}
int main(int argc, char const *argv[])
{
	while(scanf("%d %d %d", &capacity_first, &capacity_second, &capacity_third) == 3)
	{

		if (capacity_first == 0 && capacity_second == 0 && capacity_third == 0)
		{
			break;
		}
		if (capacity_first == 0 || capacity_first % 2 != 0)
		{
			printf("NO\n");
			continue;
		}
		bfs();

	}
	return 0;
}
