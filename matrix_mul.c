#include<stdio.h>
int matrix1[10][10],matrix2[10][10],multiply[10][10],n;
void read(int num)
{
    int n=num;
    int matrix1[10][10],matrix2[10][10];
    printf("Enter matrix 1 \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
          scanf("%d",&matrix1[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
          scanf("%d",&matrix2[i][j]);
        }
    }

}
void multiply1(int num )
{
    int multiply[10][10],n=num;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
          multiply[i][j]+= matrix1[i][j]*matrix2[j][i];
        }
    }
}
void display(int num)
{
    int multiply[10][10],n=num;
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",multiply[i][j]);
        }
        printf("/n");
    }
}
int main()
{
    printf("Enter the number of rows\n");
    scanf("%d",&n);
    read(n);
    multiply1(n);
    display(n);
    return 0;

}
