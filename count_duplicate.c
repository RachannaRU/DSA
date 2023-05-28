#include<stdio.h>
int duplicate(int a[],int n,int x)
{
    int c=0;
    for(int i=0; i<n; i++)
    {
        if(a[i]==x)
            c++;
    }
    return c;
}
int main()
{
    int a[20],b[20],c,n;
    FILE *fp;
    fp=fopen("matrix.txt","r");
    printf("Enter number of elements\n");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        fscanf(fp,"%d",&a[i]);
    }
    for(int i=0; i<n; i++)
    {

        int x=a[i];
        c=duplicate(a,n,x);
        printf("%d repeated %d times\n",x,c);
    }
}
