#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

int dp[(1 << 16) + 10];

int dx[] = {0,-1,0,1,0};
int dy[] = {0,0,-1,0,1};


void bfs()
{
    memset(dp,-1,sizeof(dp));
    queue<int> q;
    q.push(0);
    dp[0] = 0;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(int i = 0;i < 16;i ++)
        {
            int next = cur;
            int x = i / 4;
            int y = i % 4;
            for(int j = 0;j < 5;j ++)
            {
                int nextx = x + dx[j];
                int nexty = y + dy[j];
                if(nextx < 0 || nexty < 0 || nextx >= 4 || nexty >= 4)
                    continue;
                int pos = nextx * 4 + nexty;
                next = next ^ (1 << pos);
                
            }
            if(dp[next] >= 0)
                continue;
            dp[next] = dp[cur] + 1;
            q.push(next);
        }
    }
}

int main()
{
    char data[10];
    int state = 0;
    for(int i = 0;i < 4;i ++)
    {
        scanf("%s",data);
        for(int j = 0;j < 4;j ++)
        {
            if(data[j] == 'w')
            {
                state += (1 << (i * 4 + j));
            }
        }
    }
    bfs();
    int reverse = (~state) & ((1 << 16) - 1);
    int ans = INT_MAX;
    if(dp[state] >= 0 || dp[reverse] >= 0)
    {
        if(dp[state] >= 0)
            ans = min(ans,dp[state]);
        if(dp[reverse] >= 0)
            ans = min(ans,dp[reverse]);
        printf("%d\n",ans);
    }
    else
        printf("Impossible\n");
}