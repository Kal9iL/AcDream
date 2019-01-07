#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int F,V;
int A[110][110];
int dp[110][110];

int main()
{
    while(~scanf("%d%d",&F,&V))
    {
        for(int i = 1;i <= F;i ++)
        {
            for(int j = 1; j <= V;j ++)
            {
                scanf("%d",&A[i][j]);
            }
        }
        //dp[i][j]: 前i朵花放到前j个花瓶里所取得的最大美值


        memset(dp,0,sizeof(dp));
        for(int i = 1;i <= F;i ++)
        {
            for(int j = i; j <= V; j ++)
            {
                if(i == j)
                    dp[i][j] = dp[i - 1][j - 1] + A[i][j];
                else
                {
                    dp[i][j] = max(dp[i][j - 1],dp[i - 1][j - 1] + A[i][j]);
                }
            }
        }
        printf("%d\n",dp[F][V]);
    }
    return 0;
}