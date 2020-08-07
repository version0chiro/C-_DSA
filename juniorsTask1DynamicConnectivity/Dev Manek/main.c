#include <stdio.h>

int connected[100][2];
int arrpos = 0;

int Union(int a, int b)
{
    connected[arrpos][0] = a;
    connected[arrpos][1] = b;
    arrpos++;
    int temp = arrpos;
    for(int i = 0; i < temp; i++)
    {
        if(connected[i][1] == a)
        {
            connected[arrpos][0] = connected[i][0];
            connected[arrpos][1] = b;
            arrpos++;
        }
    }
    return 0;
}

int isConnected(int a, int b)
{
    for(int i = 0; i < arrpos; i++) {
        if((connected[i][0] == a) && (connected[i][1] == b))
        {
            printf("True\n");
            return 0;
        }

    }
    printf("False\n");
    return 0;
}

int main()
{ int n,g,x,y;
    printf("Enter number of connections you want to have:");
    scanf("%d",&n);
    for (int j = 0; j <n ; ++j) {
        printf("\nEnter value of x:");
        scanf("%d",&x);
        printf("\nEnter value of y:");
        scanf("%d",&y);
        Union(x,y);
    }
    printf("\nEnter number of connections you want to check:");
    scanf("%d",&g);
    for (int j = 0; j <g ; ++j) {
        printf("\nEnter value of x:");
        scanf("%d",&x);
        printf("\nEnter value of y:");
        scanf("%d",&y);
        isConnected(x,y);
    }
    printf("\nConnections : \n");
    for(int i = 0; i < arrpos; i++)
    {
        printf("(%d, %d) ", connected[i][0], connected[i][1]);
    }
    return 0;
}
