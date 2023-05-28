#include<stdio.h>
FILE *ip;
void Random(int num,int up,int low)
{
    for(int i=0;i<num;i++)
    {
        fprintf(ip,"%d\n",(rand()%up)+low);
    }
    rewind(ip);
}
int main()
{
    ip=fopen("matrix.txt","w");
    int num,up,low;
    printf("Enter the total numbers and its range\n");
    scanf("%d%d%d",&num,&up,&low);
    Random(num,up,low);
}
