#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 350 + 10;

int n;

int dp[N][N];

int main()
{
    scanf("%d",&n);
    memset(dp,0,sizeof(dp));
    int num;
    for(int i = 1;i <= n;i ++)
    {
        for(int j = 1;j <= i;j ++)
        {
            scanf("%d",&num);
            dp[i][j] = max(dp[i - 1][j - 1],dp[i - 1][j]) + num;
        }
    }    
    int res = -1;
    for(int i = 1;i <= n; i ++)
    {
        if(dp[n][i] > res)
        {
            res = dp[n][i];
        }
    }
    printf("%d\n",res);
}