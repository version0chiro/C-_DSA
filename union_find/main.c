#include <stdio.h>
#include <stdlib.h>
void unionJoin(int array[],int n,int p,int q){
    if(array[p]==array[q]){
        return;
    }
    else{
        array[q]=array[p];
    }
   // for(int i=0;i<n;i++)
   //     printf("%d \n",array[i]);
    }
void connected(int array[],int n,int p,int q){
    if(array[p]==array[q]){
        printf("connected");
    }
    else
        printf("not connected");
}
int main()
{   int n=10;
    int array[10]={1,2,3,4,5,6,7,8,9,10,11,12};
    unionJoin(array,n,1,7);
    unionJoin(array,n,7,9);
    unionJoin(array,n,9,10);
    unionJoin(array,n,10,12);
    unionJoin(array,n,9,11);
    unionJoin(array,n,11,5);
    unionJoin(array,n,11,3);
    unionJoin(array,n,5,7);
    connected(array,n,1,9);

    return 0;
}
