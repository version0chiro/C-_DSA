#include<stdio.h>
#include<conio.h>
#include<math.h>
int a[100];
void search();
void add();
void main()
{
  int i,j,k;
  printf("Enter the size of array: \n");
  scanf("%d",&i);
  printf("Enter elements of array :\n");
  for(j=0;j<i;j++)
  {
    scanf("%d",&a[j]);
  }
do
{
printf("Enter 1 to search or 2 to add / 0 to quit \n");
scanf("%d",&k);
if(k==1)
{
  search();
}
if (k==2)
{
  add();
}
} while(k!=0);
getch();
}
void search()
{
  int x,y,i,j,n,m,k;
  printf("Enter the start and end index:\n");
  scanf("%d%d",&x,&y);
  for(i=x;i<=y;i++)
  {
    n= (5 * a[i] * a[i]) + 4;
    m= (5 * a[i] * a[i]) - 4;
    j=sqrt(n); k=sqrt(m);
    if(j*j==n || k*k==m)
     printf("%d ", a[i]);
  }
}
void add()
{
  int x,y,val;
  printf("Enter the index and the value:\n");
  scanf("%d%d",&y,&val);
  a[y] = val;
}
