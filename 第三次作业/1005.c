/*
* @Author: TD21forever
* @Date:   2018-09-30 12:45:25
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-09-30 19:56:42
*/
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	int n, i, j, temp, tian_slow, king_slow, tian_fast, king_fast, ji;
	int tian[1001];
	int king[1001];
	int money;
	while(scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		money = 0;
		for (i = 0; i < n; ++i)
		{
			scanf("%d", &tian[i]);
		}
		for (i = 0; i < n; ++i)
		{
			scanf("%d", &king[i]);
		}
		for (i = 0; i < n - 1; ++i)
		{
			for (j = 0; j < n - i - 1; ++j)
			{
				if(tian[j] < tian[j + 1])
				{
					temp = tian[j];
					tian[j] = tian[j + 1];
					tian[j + 1] = temp;
				}
				if(king[j] < king[j + 1])
				{
					temp = king[j];
					king[j] = king[j + 1];
					king[j + 1] = temp;
				}
			}
		}
		tian_fast = king_fast = 0;
		j = 0;
		ji = 0;
		tian_slow = king_slow = n - 1;
		while(1)
		{
			if(ji == n)
			{
				break;
			}
			if(tian[tian_fast] > king[king_fast]) //田忌最快的马比国王最快的马 快
			{
				money += 200;
				tian_fast++;
				king_fast++;
				ji++;
			}
			else if(tian[tian_fast] < king[king_fast])//田忌最快的马比国王最快的马 慢
			{
				//田忌最慢的马和国王最快的马PK 输了
				tian_slow--;
				king_fast++;
				money -= 200;
				ji++;
			}
			else // tian 和 king 的速度一样快
			{
				if(tian[tian_slow] > king[king_slow]) //田忌最慢的马比国王最慢的马 快
				{
					tian_slow--;						//先赢了再说
					king_slow--;
					money += 200;
					ji++;
				}
				else if (tian[tian_slow] < king[king_slow])
				{
					king_fast++;
					tian_slow--;				//田忌最慢的马比国王最慢的马 慢
					money -= 200;				//反正总是输 还不如输给最厉害的
					ji++;
				}
				else if (tian[tian_slow] == king[king_slow])
				{
					//如果一样的也输了算了 打破平衡
					if (tian[tian_slow] < king[king_fast])
					{

						money -= 200;

					}
					ji++;
					king_fast++;
					tian_slow--;

				}

			}
		}
		printf("%d\n", money);
	}

	return 0;
}