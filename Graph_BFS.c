#include<stdio.h>

int queue[100];

int front=0,back=0;

void push(int var)
{
    queue[back] = var;
    back++;
}

void pop()
{
    queue[front] = 0;
    front++;
}

int visited[7] = {0};

int main()
{
    int N  = 6;

    int graph[6][6]={{0,1,1,0,0,0},
                     {1,0,1,0,0,0},
                     {1,1,0,1,1,0},
                     {0,0,1,0,0,0},
                     {0,0,1,0,0,1},
                     {0,0,0,0,1,0}};

    push(1);
    visited[0] = 1;
    while(front != back)
    {
        int current = queue[front];

        printf("%d ", current);

        pop();

        for(int i=0;i<6;i++)
        {
            if((graph[current-1][i] == 1) && (visited[i] == 0))
            {
                visited[i] = 1;
                push(i+1);
            }
        }
    }
    return 0;
}
