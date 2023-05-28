#include<stdio.h>
int main()
{
    FILE *fp,*fptr;
    int a[10][10],r,c;
    fp=fopen("Transpose.txt","r");
    fptr=fopen("Transposewrite.txt","w");
    fscanf(fp,"%d",&r);
    fscanf(fp,"%d",&c);
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            fscanf(fp,"%d ",&a[i][j]) ;
        }
    }
    for(int i=0; i<c; i++)
    {
        for(int j=0; j<r; j++)
        {
            fprintf(fptr,"%d ",a[j][i]);
        }
        fprintf(fptr,"\n");
    }
    fclose(fp);
    fclose(fptr);

}
