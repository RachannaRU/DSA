#include<stdio.h>
int main()
{
    int chess[8][8];
    printf("Black\n");
    for(int i=1; i<9; i++)
    {
        for(int j=1; j<9; j++)
        {
            if((i==1&&j==1)||(i==8&&j==1)){printf("E ");chess[i][j]='E';}
            else if((i==1&&j==2)||(i==8&&j==2)){printf("H ");chess[i][j]='H';}
            else if((i==1&&j==3)||(i==8&&j==3)){printf("n ");chess[i][j]='n';}
            else if((i==1&&j==4)||(i==8&&j==4)){printf("K ");chess[i][j]='K';}
            else if((i==1&&j==5)||(i==8&&j==5)){printf("Q ");chess[i][j]='Q';}
            else if((i==1&&j==6)||(i==8&&j==6)){printf("n ");chess[i][j]='n';}
            else if((i==1&&j==7)||(i==8&&j==7)){printf("H ");chess[i][j]='H';}
            else if((i==1&&j==8)||(i==8&&j==8)){printf("E ");chess[i][j]='E';}

            else if(i==2||i==7){printf("P ");chess[i][j]='P';}

            else {printf("* ");chess[i][j]='*';}
        }
        printf("\n");
    }
    char m;
    int i,j;
    printf("Enter a character for piece to move\n");
    scanf("%c",&m);
    printf("\nEnter the position\n");
    scanf("%d %d",&i,&j);
    chess[i][j]=m;
    for(int i=1;i<9;i++)
    {
        for(int j=1;j<9;j++)
        {
            printf("%c ",chess[i][j]);
        }
        printf("\n");
    }
}
