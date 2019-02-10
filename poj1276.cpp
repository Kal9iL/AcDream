#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN =  100000 + 10;
int cash;
int N;
int dp[MAXN];
int n,d;

int main()
{
    while(~scanf("%d",&cash))
    {
        memset(dp,-1,sizeof(dp));
        dp[0] = 0;
        scanf("%d",&N);
        for(int i = 0;i < N;i ++)
        {
            scanf("%d%d",&n,&d);
            for(int j = 0; j <= cash;j ++)
            {
                if(dp[j] >= 0)
                {
                    dp[j] = n;
                }
                else
                {
                    if(j < d || dp[j - d] < 0)
                    {
                        dp[j] = -1;
                    }
                    else
                    {
                        dp[j] = dp[j - d] - 1;
                    }
                    
                }
            }
        }
        for(int i = cash; i >= 0; i --)
        {
            if(dp[i] >= 0)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
}