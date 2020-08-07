#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<conio.h>
findProfit(int a[],int n){
    bool buyFlag=1;
    bool sellFlag=0;
    int bought=a[0];
    int sold=0;
    int profit=0;
    int maxProfit=0;
    for(int i=0;i<n;i++){
        if(a[i]<bought|| buyFlag==0){
            bought=a[i];
            printf("\nbought at %d",bought);
            buyFlag=1;
        }
        if(i==n-1){
            buyFlag=0;
            sellFlag=1;
            sold=a[i];
            printf("\n sold at %d",sold);
        }
        else if(a[i]>a[i+1] && i!=0){
            buyFlag=0;
            sellFlag=1;
            sold=a[i];
            printf("\n sold at=%d",sold);
        }
        if( sellFlag==1){
            profit=abs(sold-bought);
            printf("\n profit=%d",profit);
            maxProfit=maxProfit+profit;

            sellFlag=0;
        }

    }
    printf("\n Maximum profit is %d",maxProfit);
}


void main(){

    //int n=8;
    //int a[8]={100,50,180,260,310,40,535,695};
    int n;
    int a[100];
    printf("Enter the number of days \n");
    scanf("%d",&n);
    printf("enter prices of each day respectively");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\n entered array of price is ={");
    for(int i=0;i<n;i++){
        if(i==n-1)
            printf("%d",a[i]);
        else
            printf("%d ,",a[i]);
    }
    printf("}");
    findProfit(a,n);
}
