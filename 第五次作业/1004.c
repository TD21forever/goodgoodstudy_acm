#include <stdio.h>
#include <stdlib.h>
#define size 2005
#define INIF 2147483646
 
//https://blog.csdn.net/u011073831/article/details/11851643
int f[size][1005];
int minn(int a,int b)
{
    return a<=b?a:b;
}
int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;// 从小到大排序
}
int main()
{
    int n,k,i,j;
    int val[size]={0};
    f[0][0]=0;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
 
        val[0]=0;
        for(i=1; i<=n; i++)
            scanf("%d",&val[i]);
        qsort(val+1,n,sizeof(val[0]),cmp);
        for(i=0; i<=n; i++)
            for(j=1; j<=k; j++)
                f[i][j]=INIF;
 
        for(i=2; i<=n; i++)
            for(j=1; j*2<=i; j++)
                f[i][j]=minn(f[i-2][j-1]+(val[i]-val[i-1])*(val[i]-val[i-1]),f[i-1][j]);
        printf("%d\n",f[n][k]);
    }
    return 0;
}