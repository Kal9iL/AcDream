#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 100 + 10;

int dp[MAXN][MAXN];
int n,m,k,s;
int exp[MAXN];
int torl[MAXN];

int main()
{
    while(~scanf("%d%d%d%d",&n,&m,&k,&s))
    {
        for(int i = 0;i < k; i ++)
        {
            scanf("%d%d",&exp[i],&torl[i]);
        }
        memset(dp,0,sizeof(dp));
        // for(int c = 1;c <= s;c ++)  //杀怪的个数
        // {
        //     for(int i = 0;i < k; i ++) // 杀第i种怪 01背包
        //     {
        //         for(int j = 0; j <= m; j ++) // 忍耐值
        //         {
        //             if(j < torl[i])
        //                 dp[c][j] = max(dp[c - 1][j], dp[c][j]);
        //             else
        //                 dp[c][j] = max(dp[c - 1][j], max(dp[c - 1][j - torl[i]] + exp[i],dp[c][j]));
        //         }
        //     }
        // }

        for(int i = 0;i < k ;i ++)
        {
            for(int j = torl[i]; j <= m;j ++)
            {
                for(int k = 1; k <= s; k ++)
                {
                    dp[k][j] = max(dp[k][j], dp[k - 1][j - torl[i]] + exp[i]);
                    
                }
            }
        }
        // for(int c = 1; c <=s ; c ++)
        // {
        //     for(int i = 0;i <= m; i ++)
        //     {
        //         printf("%2d ",dp[c][i]);
        //     }
        //     printf("\n");
        // }
        int ans = -1;
        for(int i = 0;i <= m; i ++)
        {
            for(int j = 1; j <= s;j ++)
            {
                if(dp[j][i] >= n)
                {
                    ans = m - i;
                    break;
                }
            }
            if(ans >= 0)
            {
                break;
            }
        }
        printf("%d\n",ans);
    }
}


//如果每种物品只能取1件

// for(int i = 0;i < n;i ++) //
// {
//     for(int c = 1; c <= i + 1; c ++)
//     {
//         for(int j = 0;j <= m;j ++)
//         {
//             dp[c][j] = max(max(dp[c - 1][j],dp[c - 1][j - w[i]] + v[i]),dp[c][j]);
//         }
//     }
// }