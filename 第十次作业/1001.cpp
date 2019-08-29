#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

//两直线相交 模板
struct point
{
    double x,y;
};
point m1[100],m2[100];
double min(double x,double y)
{
    return x<y?x:y;
}
double max(double x,double y)
{
    return x>y?x:y;
}
double direction(point pi,point pj,point pk)//二维叉乘 有向平行四边形的面积 
{
    return (pk.x-pi.x)*(pj.y-pi.y)-(pj.x-pi.x)*(pk.y-pi.y);
}
bool on_segment(point pi,point pj,point pk)
{
    if(pk.x>=min(pi.x,pj.x)&&pk.x<=max(pi.x,pj.x)&&pk.y>=min(pi.y,pj.y)&&pk.y<=max(pi.y,pj.y))
        //x大于最小值 小于最大值 y大于最小值 小于最大值 说明pk在pipj的直线上
        return true;
    return false;
}
bool segments_intersect(point p1,point p2,point p3,point p4)//判断是否有交点
{   //p1p2是一条线 p3p4是另一条线
    double d1=direction(p3,p4,p1);//p3p4 and p3p1 求叉乘
    double d2=direction(p3,p4,p2);
    double d3=direction(p1,p2,p3);
    double d4=direction(p1,p2,p4);
    if(d1*d2<0&&d3*d4<0)//点p1和点p2在线p3p4的两侧 点P3和点p4在线p1p2的两侧 
        return true;
    else if(d1==0&&on_segment(p3,p4,p1))//p1在线段p3p4上
        return true;
    else if(d2==0&&on_segment(p3,p4,p2))
        return true;
    else if(d3==0&&on_segment(p1,p2,p3))
        return true;
    else if(d4==0&&on_segment(p1,p2,p4))
        return true;
    return false;
}
int main()
{
    int n,sum;
    while(cin>>n&&n)
    {
        for(int i=0; i<n; i++)
            scanf("%lf%lf%lf%lf",&m1[i].x,&m1[i].y,&m2[i].x,&m2[i].y);
        sum=0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(segments_intersect(m1[i],m2[i],m1[j],m2[j]))
                    sum++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}