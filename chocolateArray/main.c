#include <stdio.h>
int a[100];
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}
int findMinDif(int a[],int n,int m){
    int minimumDiff=100000;
    for(int i=0;i<n;i++){
        if(a[i+m-1] - a[i]<minimumDiff && a[i+m-1] - a[i]>0){
            minimumDiff=a[i+m-1] - a[i];
        }
    }
   return minimumDiff;
}
int main() {
	int n,m,t;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    bubbleSort(a,n);
    printf("%d \n",findMinDif(a,n,m));
}
