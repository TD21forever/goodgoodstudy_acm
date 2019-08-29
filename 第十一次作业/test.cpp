#include<stdio.h>

int main()
{
    int n,x,y;
    scanf("%d",&n);

        while(n--)
        {
            scanf("%d%d",&x,&y);

           
            if (x%(y+1)==0)
             printf("sceond\n");
            else
           printf("first\n");
        
        }
    
    return 0;
}