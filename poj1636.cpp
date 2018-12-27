#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int n,m,r;
int rlt[200 + 10][200 + 10];
int vis[2][200 + 10];
int dp[200 + 10][200 + 10];

int value[200 + 10];
int weight[200 + 10];
int side0,side1;

void dfs(int side,int k)
{
    vis[side][k] = 1;
    
    if(side)
    {
        side1 ++;
        for(int i = 1;i <= m;i ++)
        {
            if(rlt[i][k] && ! vis[0][i])
            {
                dfs(0,i);
            }
        }
    }
    else
    {
        side0 ++;
        for(int i = 1;i <= m;i ++)
        {
            if(rlt[k][i] && ! vis[1][i])
            {
                dfs(1,i);
            }
        }
    }
}

int main()
{
   
    scanf("%d",&n);
    while(n --)
    {
        memset(rlt,0,sizeof(rlt));
        memset(vis,0,sizeof(vis));
        memset(dp,0,sizeof(dp));
        scanf("%d%d",&m,&r);
        for(int i = 0;i < r;i ++)
        {
            int tempa,tempb;
            scanf("%d%d",&tempa,&tempb);
            rlt[tempa][tempb] = 1;
        }
        int tot = 0;
        for(int i = 1;i <= m;i ++)
        {
            side0 = side1 = 0;
            if(!vis[0][i])
            {    
                dfs(0,i);
                value[tot] = side0;
                weight[tot] = side1;
                tot ++;
            } 
        }
        for(int i = 1;i <= m;i ++)
        {
            side0 = side1 = 0;
            if(!vis[1][i])
            {    
                dfs(1,i);
                value[tot] = side0;
                weight[tot] = side1;
                tot ++;
            }
        }
        // for(int i = 0;i < tot;i ++)
        // {
        //     printf("%d %d\n",value[i],weight[i]);
        // }
        dp[0][0] = 1;
        for(int i = 0;i < tot;i ++)
        {
            for(int w = m / 2; w >= 0; w --)
            {
                for(int v = m /2 ;v >= 0 ; v --)
                {
                    if(w - weight[i] < 0 || v - value[i] < 0)
                        continue;
                    if(dp[w][v] || dp[w - weight[i]][v - value[i]])
                    {
                        dp[w][v] = 1;
                    }
                }
            }
        }
        for(int i = m / 2; i >= 0;i --)
        {
            if(dp[i][i])
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
