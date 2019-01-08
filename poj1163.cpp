#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int N;
int num[110][110];
int dp[110][110];

int main()
{
    while(~scanf("%d",&N))
    {
        for(int i = 1;i <= N;i ++)
        {
            for(int j = 1; j <= i ;j ++)
            {
                scanf("%d",&num[i][j]);
            }
        }
        memset(dp,0,sizeof(dp));
        for(int i = 1;i <= N; i ++)
        {
            for(int j = 1;j <= i; j ++)
            {
                dp[i][j] = max(dp[i - 1][j - 1] ,dp[i - 1][j]) + num[i][j];
            }
        }
        int ans = -1;
        for(int i = 1;i <= N;i ++)
        {
            if(ans < dp[N][i])
                ans = dp[N][i];
        }
        printf("%d\n",ans);
    }        
    return 0;
}