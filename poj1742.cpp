#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 100 + 10;
const int M = 100000 + 10;

int n,m;
int A[N],C[N];
int dp[M];

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n == 0 && m == 0)
        {
            break;
        }
        for(int i = 0;i < n;i ++)
        {
            scanf("%d",&A[i]);
        }
        for(int i = 0;i < n; i ++)
        {
            scanf("%d",&C[i]);
        }
        memset(dp,-1,sizeof(dp));
        dp[0] = 0;
        for(int i = 0;i < n;i ++)
        {
            for(int j = 0;j <= m; j ++)
            {
                if(dp[j] >= 0)
                {
                    dp[j] = C[i];
                }
                else
                {
                    if(j < A[i] || dp[j - A[i]] < 0)
                    {
                        dp[j] = -1;
                    }
                    else
                    {
                        dp[j] = dp[j - A[i]] - 1;
                    }
                }
                
            }
        }
        int ans = 0;
        for(int i = m;i >= 1 ;i --)
        {
            if(dp[i]>= 0)
            {
                ans ++;
            }
        }
        printf("%d\n",ans);
    }
}