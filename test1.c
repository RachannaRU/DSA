#include<stdio.h>
int main()
{
    int a,b[10];
      int temp;
    FILE *fp;
    fp=fopen("file1.txt","r");
    fscanf(fp,"%d",&a);
    for(int i=0;i<a;i++)
    {
        fscanf(fp,"%d",&b[i]);
    }
    for(int j=0;j<a;j++)
    {
      for(int i=0;i<a-1;i++)
      {
          if(b[i]<b[i+1])
          {
              temp=b[i];
              b[i]=b[i+1];
              b[i+1]=temp;
          }
      }
    }
    for(int i=0;i<a;i++)
    {
        printf("%d",b[i]);
        printf("\n");
    }

    fclose(fp);
}
