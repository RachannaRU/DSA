#include<stdio.h>
int main()
{
    int random,lower,upper,i;
    FILE *fp;
    fp=fopen("sorting.txt","w");
    printf("Enter the upper , lower and amount of numbers\n");
    scanf("%d %d %d",&lower,&upper,&i);
    for(int j=0;j<i;j++)
    {
        random=(rand()%(upper-lower+1))+lower;
        fprintf(fp,"%d\n",random);
    }
    fclose(fp);
    return 0;
}
