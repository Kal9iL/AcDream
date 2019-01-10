#include <cstdio>
#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int raw_data[200];
int data[110],sys[110];
int dpmax[100 + 10][100 + 10];
int dpmin[110][110];

bool vis[110][110];
int N;

void rearrange(int pos)
{
    int ksys = 0;
    int kdata = 0;
    int offset = pos * 2 + 1;
    for(int i = 0; i < N * 2 - 1; i ++)
    {
        if(raw_data[(offset + i) % (2 * N)] > 32767)
        {
            sys[ksys ++ ] = raw_data[(offset + i) % (2 * N)]  - 32767; 
        }
        else
        {
            data[kdata ++] = raw_data[(offset + i) % (2 * N)];
        }
    }
    return ;    
}

void dfs(int l,int r)
{
    if(vis[l][r])
        return ;
    if(l == r)
    {
        dpmin[l][r] = dpmax[l][r] = data[l];
        vis[l][r] = 1;
        return ;
    }
    for(int k = l;k < r;k ++)
    {
        dfs(l,k);
        dfs(k + 1, r);
        if(sys[k] == 1)
        {
            int t1 = dpmin[l][k] + dpmin[k + 1][r];
            int t2 = dpmin[l][k] + dpmax[k + 1][r];
            int t3 = dpmax[l][k] + dpmin[k + 1][r];
            int t4 = dpmax[l][k] + dpmax[k + 1][r];
            int maxt = max(t1,max(t2,max(t3,t4)));
            int mint = min(t1,min(t2,min(t3,t4)));
            dpmax[l][r] = max(maxt,dpmax[l][r]);
            dpmin[l][r] = min(mint,dpmin[l][r]);
        }
        else
            if(sys[k] == 2)
            {
                int t1 = dpmin[l][k] * dpmin[k + 1][r];
                int t2 = dpmin[l][k] * dpmax[k + 1][r];
                int t3 = dpmax[l][k] * dpmin[k + 1][r];
                int t4 = dpmax[l][k] * dpmax[k + 1][r];
                int maxt = max(t1,max(t2,max(t3,t4)));
                int mint = min(t1,min(t2,min(t3,t4)));
                dpmax[l][r] = max(maxt,dpmax[l][r]);
                dpmin[l][r] = min(mint,dpmin[l][r]);
            }
    }
    vis[l][r] = 1;
    return;
}

int main()
{
    while(~scanf("%d",&N))
    {
        char temp[200];
        for(int i = 0;i < N * 2; i ++)
        {
            scanf("%s",temp);
            if(temp[0] == 't' ||temp[0] == 'x' )
            {
                if(temp[0] == 't')
                {
                    raw_data[i] = 32767 + 1;
                }
                else
                {
                    raw_data[i] = 32767 + 2;
                }
            }
            else
            {
                if(temp[0] == '-')
                {
                    int k = 1;
                    int value = 0;
                    while(temp[k])
                    {
                        value = value * 10 + (temp[k] - '0');
                        k ++;
                    }
                    raw_data[i] = -value;
                }
                else
                {
                    int k = 0;
                    int value = 0;
                    while(temp[k])
                    {
                        value = value * 10 + (temp[k] - '0');
                        k ++;
                    }
                    raw_data[i] = value;
                }
            }
        }
        int ans = -INT_MAX;
        int anslist[50 + 10];
        int countans = 0;
        for(int j = 0;j < N; j ++)
        {
            memset(data,0,sizeof(data));
            memset(sys,0,sizeof(sys));
            rearrange(j);
            memset(vis,0,sizeof(vis));
            memset(dpmax,0x80,sizeof(dpmax));
            memset(dpmin,0x7f,sizeof(dpmin));
            dfs(0,N - 1);
            int candi = dpmax[0][N-1];
            if(ans < candi)
            {
                ans = candi;
                countans  = 0;
                anslist[countans ++] = j + 1;
            }
            else
            {
                if(ans == candi)
                {
                    anslist[countans ++] = j + 1;
                }
            }
        }
        printf("%d\n",ans);
        for(int j = 0;j < countans ;j ++)
        {
            if(j == 0)
                printf("%d",anslist[j]);
            else
                printf(" %d",anslist[j]);
        }
        printf("\n");
    }
}