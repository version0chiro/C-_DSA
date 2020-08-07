#include <stdio.h>
#include <stdlib.h>

int rotateArray(int *a,int d,int n){

    for(int i=0;i<d;i++)
        leftRotatebyOne(a,n);
}
int leftRotatebyOne(int *a,int n){
    int temp=a[0],i;
    for(i=0;i<n-1;i++)
        a[i]=a[i+1];
    a[i]=temp;
}
int main()
{
    int a[10];
    int d=3,n=5;
//    scanf("%d %d",&n,&d);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    rotateArray(a,d,n);
    for(int i=0;i<n;i++){
        printf(" %d ",a[i]);
    }
    return 0;
}
