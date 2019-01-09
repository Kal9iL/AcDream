#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int startking;
int startknight[64 + 10];

int distknight[64 + 10][64 + 10];
int distking[64 + 10][64 + 10];
int vis[64 + 10];
int NumKnight;

int dnx[] = {-1, +1, -1, -2, -2, +2, +1, +2};
int dny[] = {-2, -2, +2, -1, +1, -1, +2, +1};
int dkx[] = {-1,-1, +1, -1, +1, +1,  0,  0};
int dky[] = {-1, 0, -1, +1,  0, +1, -1, +1};

void caldistknight(int start)
{
    queue<int> q;
    q.push(start);
    q.push(0);
    vis[start] = 1;
    while(!q.empty())
    {    
        int pos = q.front();
        q.pop();
        int steps = q.front();
        q.pop();
        distknight[start][pos] = steps;
        int x = pos / 8;
        int y = pos % 8;
        for(int i = 0;i < 8; i ++)
        {
            int tempx = x + dnx[i];
            int tempy = y + dny[i];
            
            if(tempx < 0 || tempx >= 8 || tempy < 0 || tempy >= 8)
                continue;

            if(!vis[tempx * 8 + tempy])
            {
                q.push(tempx * 8 + tempy);
                q.push(steps + 1);
                vis[tempx * 8 + tempy] = 1;
            }
        }
    }
}

void caldistking(int start)
{
    queue<int> q;
    q.push(start);
    q.push(0);
    vis[start] = 1;
    while(!q.empty())
    {    
        int pos = q.front();
        q.pop();
        int steps = q.front();
        q.pop();
        vis[pos] = 1;
        distking[start][pos] = steps;
        int x = pos / 8;
        int y = pos % 8;
        for(int i = 0;i < 8; i ++)
        {
            int tempx = x + dkx[i];
            int tempy = y + dky[i];
            if(tempx < 0 || tempx >= 8 || tempy < 0 || tempy >= 8)
                continue;
            if(!vis[tempx * 8 + tempy])
            {
                q.push(tempx * 8 + tempy);
                q.push(steps + 1);
                vis[tempx * 8 + tempy] = 1;
            }
        }
    }
}

int solve()
{
    int tot = 0x7f7f7f7f;
    int finalend = -1;
    int meet = -1;
    for(int end = 0;end < 64; end ++)  //枚举终点位置
    {
        //枚举king的位置
        for(int i = 0; i < 64; i ++)
        {
            // 选择哪个骑士和国王一起走
            
            for(int j = 0; j <= NumKnight; j ++)
            {
                int tottemp = 0; 
                if(j == NumKnight)
                {
                    for(int k = 0; k < NumKnight; k ++)
                    {
                        tottemp += distknight[startknight[k]][end];
                    }
                    tottemp += distking[startking][i] + distking[i][end];
                }
                else
                {
                    for(int k = 0; k < NumKnight; k ++)
                    {
                        if(k == j)
                        {
                            tottemp += (distking[startking][i] + distknight[startknight[k]][i] + distknight[i][end]);
                        }
                        else
                        {
                            tottemp += distknight[startknight[k]][end];
                        }
                    }
                }
                if(tot > tottemp)
                {
                    finalend = end;
                    meet = i;
                    tot = tottemp;
                }

            }
        }
    }
    return tot;
}


int main()
{
    char data[200];
    while(~scanf("%s",data))
    {
        int len = strlen(data);
        NumKnight = 0;
        for(int i = 0;i < len; i += 2)
        {
            if(i == 0)
            {
                startking = (data[i] - 'A') * 8 + (data[i + 1] - '1');
            }
            else
            {
                startknight[NumKnight ++] = (data[i] - 'A') * 8 + (data[i + 1] - '1');
            }
        }
        memset(distknight,0x7f,sizeof(distknight));
        memset(distking,0x7f,sizeof(distking));
        for(int i = 0; i < 64; i ++)
        {
            memset(vis,0,sizeof(vis));
            caldistking(i);
        }
        for(int i = 0; i < 64; i ++)
        {
            memset(vis,0,sizeof(vis));
            caldistknight(i);
        }
        int ans = solve();
       printf("%d\n",ans);
    }        
}