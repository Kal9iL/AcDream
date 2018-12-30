#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int R,C;

int dp[100 + 10][100 + 10];
int height[100 + 10][100 + 10];
int ans ;

int solve(int x, int y)
{
    if(x <= 0 || y <= 0 || x > R || y > C)
        return 0;
    if(dp[x][y] > 0)
    {
        return dp[x][y];
    }
    int dx[] = {0, -1, 0, 1};
    int dy[] = {-1, 0, 1, 0};
    int mlen = 0;
    for(int i = 0; i  < 4; i ++)
    {
        if(height[x + dx[i]][y + dy[i]] < height[x][y])
        {
            mlen = max(mlen,solve(x + dx[i],y + dy[i]));
        }   
    }
    dp[x][y] = mlen + 1;
    return dp[x][y];
}
int main()
{
    while(~scanf("%d%d",&R,&C))
    {
        memset(height,-1,sizeof(height));

        for(int i = 1;i <= R; i ++)
        {
            for(int j = 1;j <= C;j ++)
            {
                scanf("%d",&height[i][j]);
            }
        }
        
        memset(dp,0,sizeof(dp));

        ans = 0;

        for(int i = 1;i <= R; i ++)
        {
            for(int j = 1; j <= C; j ++)
            {
                ans = max(ans,solve(i,j));
            }
        }
        printf("%d\n",ans);
    }
}