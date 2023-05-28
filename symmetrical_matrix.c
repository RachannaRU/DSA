#include<stdio.h>
int main()
{
    int a[5][5],x,y,status;
    FILE *fp;
    fp=fopen("matrix.txt","r");
    scanf("%d%d",&x,&y);
    if(x==y)
    {
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<x;j++)
            {
                fscanf(fp,"%d",&a[i][j]);
            }
        }
         for(int i=0;i<x;i++)
        {
            for(int j=0;j<x;j++)
            {
               if(a[i][j]==a[j][i])
                status=1;
               else
               {
                  status=0;
                  break;
               }
            }
        }
        if(status==1)
          printf("Symmetric");
        else
          printf("Not symmetric");
    }
    else
        printf("Row and columns should be same\n");
}
