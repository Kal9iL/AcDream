#include <cstdio>
#include <iostream>
#include <cstring>
#include <climits>
#include <queue> 

using namespace std;

int r,c;
char data[300][300];
int dis[300][300];

void bfs()
{
    queue<int> q;
    memset(dis,-1,sizeof(dis));
    for(int i = 0;i < r; i ++)
    {
        for(int j = 0;j < c; j ++)
        {
            if(data[i][j] == '1')
            {
                q.push(i * c  + j);
                dis[i][j] = 0;      
            }
            else
            {
                dis[i][j] = INT_MAX;
            }
        }
    }
    int dx[] = {-1,0,1,0};
    int dy[] = {0,-1,0,1};
    while(!q.empty())
    {
        int pos = q.front();
        q.pop();
        int x = pos / c;
        int y = pos % c;
        for(int i = 0;i < 4;i ++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if(tx < 0 || tx >= r || ty < 0 || ty >= c || dis[tx][ty] < INT_MAX){
                continue;
            }
            dis[tx][ty] = dis[x][y] + 1;
            q.push(tx * c+ ty);
        }
    }
}

bool check(int x)
{
    bool ok = true;
    int maxplus = INT_MAX,minplus= -INT_MAX, maxminus = INT_MAX,minminus = -INT_MAX;
    for(int i = 0; i < r; i ++)
    {
        for(int j = 0; j < c; j ++)
        {
            if(dis[i][j] > x)
            {
                maxplus = min(i + j + x, maxplus);
                minplus = max(i + j - x, minplus);
                maxminus = min(i - j + x, maxminus);
                minminus = max(i - j - x, minminus);
                ok = false;
            }
        }
    }
    if(ok)
        return true;
    for(int i = 0;i < r;i ++)
    {
        for(int j = 0;j < c;j ++)
        {
            int plus = i + j,minus = i - j;
            if(plus <= maxplus && plus >= minplus && minus <= maxminus && minus >= minminus)
            {
                return true;
            }
        }
    }  
    return false;  
}


int main()
{
    int t;
    scanf("%d",&t);
    for(int ics = 1; ics <= t; ics ++)
    {
        printf("Case #%d: ",ics);
        scanf("%d%d",&r,&c);
        for(int i = 0;i < r ;i ++)
        {
            scanf("%s",data[i]);
        }
        bfs();
        int left = 0, right = r * c ;
        int ans = INT_MAX;
        while(left <= right)
        {
            int mid = (left + right) >> 1;
            if(check(mid))
            {
                ans = min(ans,mid);
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        printf("%d\n",ans);
    }
}