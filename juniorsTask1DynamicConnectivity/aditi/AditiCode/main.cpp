#include<stdio.h>
#include<conio.h>
#include<string.h>
int map[100][100]={0};
void unionof(int,int);
int isconnected(int,int);
int main()
{
  int x,y,z,w;
  int flag;
  printf("Enter values of x and y for union (x,y) and 0 0  after completion of input:\n");
  while(z!=0)
  {
  printf("union: ");
  scanf("%d %d",&x,&y);
  z=x;
  if (z==0)
  break;
  unionof(x,y);
  }
  printf("Enter values of x and y for isconnected(x,y) and 0 0 after completion of input:\n \n");
  while(w!=0)
  {
  printf("isconnected: ");
  scanf("%d %d",&x,&y);
  w=x;
  if(w==0)
  {
    break;
  }
  flag=isconnected(x,y);
  if(flag==1)
  printf("True \n");
  else
  printf("False \n");
  }
return 0;
}
void unionof(int x,int y)
{
int i=0,j,l,k;
if (map[0][0]==0)
{
  map[0][0]=x;
  map[1][0]=y;
}
else
{
for(j=0;j<100;j++)
{
for(i=0;i<100;i++)
  {
    if (map[i][j]==x)
    {
      if (map[i+1][j]==0)
      map[i+1][j]=y;
      else
      {
        for (l=1;l<100;l++)
        {
        if( map[0][l]==0)
        {
        for(int k=i;k>=0;k--)
        {
        map[k][l]=map[k][l-1];
        j=l;
        }
        map[i+1][j]=y;
        break;
        }
      }
    }
    }
}
}
}
}
int isconnected(int x,int y)
{
  int j,i,k,flag;
  for(j=0;j<100;j++)
  {
    for(i=0;i<100;i++)
    {
      if(map[i][j]==x)
      {
        for(k=i;k<100;k++)
        {
          if(map[k][j]==y)
          {
          flag=1;
          goto n;
          }
        }
      }
    }
  }
n:return flag;
}
