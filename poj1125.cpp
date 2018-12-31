#include <cstdio>
#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

const int MAXN = 100 + 10;

int rel[MAXN][MAXN];
int dis[MAXN];
int vis[MAXN];
int n;
int start_point,ans;

void solve()
{
    ans = INT_MAX;
    start_point = 0;
    for(int i = 1;i <= n;i ++)
    {
        memset(dis,0x7f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        dis[i] = 0;
        int v,vt;
        vt = i;
        for(int j = 1;j < n;j ++)
        { 
            v = vt;
            vis[v] = 1;
            int min_dis = INT_MAX;
            
            for(int k = 1; k <= n;k ++)
            {
                if(vis[k])
                    continue;
                if(rel[v][k] != -1 && dis[k] > dis[v] + rel[v][k])
                {
                    dis[k] = dis[v] + rel[v][k];
                }
                if(min_dis > dis[k])
                {
                    min_dis = dis[k];
                    vt = k;
                }
            }
        }
        bool flag = true;
        int t_max = -1;
        for(int s = 1;s <= n;s ++)
        {
            
            if(dis[s] >= 0x7f7f7f7f)
            {    
                flag = false;
                break;
            }
            if(t_max < dis[s])
                t_max = dis[s];
        }
        if(flag)
        {    
            if(ans > t_max)
            {
                ans = t_max;
                start_point = i;
            }
        }
    }
}

int main()
{
    while(scanf("%d",&n ) && n)
    {
        memset(rel,-1,sizeof(rel));
        int numcat;
        for(int i = 1;i <= n;i ++)
        {
            scanf("%d",& numcat);
            for(int j = 0;j < numcat;j ++)
            {
                int id,it;
                scanf("%d%d",&id,&it);
                rel[i][id] = it;
            }
        }
        solve();
        if(start_point == 0)
            printf("disjoint\n");
        else
            printf("%d %d\n",start_point,ans);
    }
}