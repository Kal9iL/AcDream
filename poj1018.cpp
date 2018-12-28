#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>

using namespace std;
int data[100 + 10][100 + 10][2];
int count[100 + 10];
int dp[10000 + 10][100 + 10];
int countdp[1000];
map<int,int> m;


int main()
{
    int t,n;
    scanf("%d",&t);
    int k = 1;
    while(t --)
    {
        scanf("%d",&n);
        memset(countdp,0,sizeof(countdp));
        memset(data,0,sizeof(data));
        memset(count,0,sizeof(count));
        memset(dp,0,sizeof(dp));

        for(int i = 0;i < n;i ++)
        {
            scanf("%d",&count[i]);
            for(int j = 0;j < count[i]; j ++)
            {
                scanf("%d%d",&data[i][j][0],&data[i][j][1]);  //0 bandwidth 1 price
                if(m[data[i][j][0]] == 0)
                    m[data[i][j][0]] = k ++;
            }
        }
        for(int i = 0;i < n;i ++)
        {
            for(map<int,int>::iterator it = m.begin(); it != m.end();it ++)
            {
                if(countdp[it -> second] < i)
                    continue;
                int flag = false;
                for(int  j = 0;j < count[i]; j ++)    
                {
                    if( it -> first <= data[i][j][0])
                    {
                        flag = true;
                        int pos = it -> second;
                        if(dp[pos][i + 1] == 0)
                            dp[pos][i + 1] = dp[pos][i] + data[i][j][1];
                        else
                            if(dp[pos][i] + data[i][j][1] < dp[pos][i + 1])
                            {
                                dp[pos][i + 1] = dp[pos][i] + data[i][j][1];
                            }    
                    }
                }
                if(flag)
                    countdp[it -> second] ++;
            }
        }
        double ans = 0;
        for(map<int,int>::iterator it = m.begin();it != m.end(); it ++)
        {
            if(countdp[it -> second] < n)
                continue;
            ans = max(1.0 * it -> first / dp[it -> second][n] , ans);
        }
        printf("%.3f\n",ans);
    }
    return 0;
}

//80: 25 + 40 