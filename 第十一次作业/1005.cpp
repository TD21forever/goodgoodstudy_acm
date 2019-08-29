/*
* @Author: TD21forever
* @Date:   2018-12-14 17:08:02
* @Last Modified by:   TD21forever
* @Last Modified time: 2018-12-14 17:32:54
*/
#include<bits/stdc++.h>
using namespace std;

/*
思路

这就是Nim游戏，当a1⊕a2⊕...⊕an=0（表示异或），为必败点（N点），此时后手的人必赢

所以我们要把a1⊕a2⊕...⊕an=k的状态转移到k为0的状态

要利用异或的一个性质：x⊕x=0，如果知道其他m−1堆异或的结果tmp，只要当前堆的牌的数量的大于tmp，那么就一定能留下tmp张牌使得总异或结果为0

*/


int a[110];
int main()
{
    int m;
    while(cin>>m)
    {
        if(m==0) break;
        int ans = 0 ;
        for(int i=1;i<=m;i++)
        {
            cin >> a[i];
            ans ^= a[i];
        }
        
        if(ans == 0)   //如果异或的结果为0说明怎么走都是后手的人赢
            cout << 0 << endl;
        else
        {
            int cnt = 0;
            for(int i=1;i<=m;i++)
            {
                int tmp;
                tmp = ans^a[i];   //先后两次异或相当于没有异或a[i]，是其他项异或的结果
                if(tmp < a[i]) cnt++; //只有a[i]>tmp才可能留下tmp个使得tmp^tmp=0
            }
            cout << cnt << endl;
        }
    }
    return 0;
}