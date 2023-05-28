#include<stdio.h>
#define size 100
int top=-1,stack[size];
FILE *ip,*sp,*puslog,*polog,*oplog;
void push()
{
    int num;
    stack[++top]=num;
    fscanf(ip,"%d",&num);
    fprintf(sp,"%d\n",num);
    fprintf(puslog,"%d\n",num);
    fprintf(oplog,"%d value was pushed\n",num);
}
void pop()
{
    fprintf(polog,"%d\n",stack[top]);
    fprintf(oplog,"%d value was Poped\n",stack[top]);
    top--;
}
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
    int ch;
    ip=fopen("input.txt","w");
    sp=fopen("stack.txt","a");
    puslog=fopen("pushlog.txt","a");
    polog=fopen("poplog.txt","a");
    oplog=fopen("operation_log.txt","a");
    int num,up,low;
    printf("Enter the total numbers and its range\n");
    scanf("%d%d%d",&num,&up,&low);
    Random(num,up,low);
    while(1)
    {
        printf("Enter your choice \n 1.Push \n 2.Pop \n 3.Exit \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : push();break;
            case 2 : pop();break;
            case 3 : exit(0);break;
            default : printf("Invalid input\n");
        }
    }
    fclose(ip);
    fclose(sp);
    fclose(puslog);
    fclose(polog);
    fclose(oplog);
}
