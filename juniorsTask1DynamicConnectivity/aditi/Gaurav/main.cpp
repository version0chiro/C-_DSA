///joins 2 indexs uni-directionally and also find if 2 index are connected uni-directionally
#include<iostream>
using namespace std;
int a[12]={0,1,2,3,4,5,6,7,8,9,10,11};
string isConnected(int b,int c)
{
    string t="true";
    string f="false";
    int i;
    for(i=0;i<11;i++)
        {
            int j;
            for(j=0;j<12;j++)
                {
                   if(a[j]==c*c)
                   {
                       if(j==b)
                       {
                          return t;
                       }
                       else
                        {
                            break;
                        }
                   }
                }
                if(j==12)
                {
                   return f;
                }
                else
                {
                   c=j;
                }
        }
}

void Union(int b,int c)
{
    a[b]=c*c;
}
int main()
{
    Union(1,7);
    Union(4,9);
    Union(9,7);
    Union(7,3);

    cout<<isConnected(9,7)<<endl;
    cout<<isConnected(9,1)<<endl;
    cout<<isConnected(4,3)<<endl;
}
