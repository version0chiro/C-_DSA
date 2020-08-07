#include <stdio.h>
#include <stdlib.h>
/*There are n houses build in a line,
each of which contains some value in it.
A thief is going to steal the maximal value of these houses,
but he can’t steal in two adjacent houses because the owner of the stolen houses
will tell his two neighbours left and right side.
What is the maximum stolen value?
Input: hval[] = {6, 7, 1, 3, 8, 2, 4}
Output: 19
*/

int main()
{
    int houseValue[10]={};
    int n;
    printf("\n Enter the number of house");
    scanf("%d",&n);
    printf("\n enter vale of each house");
    for(int i=0;i<n;i++){
        scanf("%d",&houseValue[i]);
    }
    return theifValue(houseValue,n);
}
int max(int a, int b){
    if (a>b)
        return a;
    else
        return b;
}
int theifValue(int houseValue[],int n){
    if (n == 0)
        return 0;
    int dp[n];
    dp[0] = houseValue[0];
    if (n == 1)
        return houseValue[0];
    if (n == 2)
        return max(houseValue[0], houseValue[1]);
    dp[1] = max(houseValue[0],houseValue[1]);
    for (int i = 2; i<n; i++)
        dp[i] = max(houseValue[i]+dp[i-2], dp[i-1]);

    return dp[n-1];
    }
