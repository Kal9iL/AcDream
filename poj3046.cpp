#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

const int N = 100000 + 10;

int T,A,S,B;
int dp[2][N];
int ant[1000 + 10];

int main()
{
    scanf("%d%d%d%d",&T,&A,&S,&B);
    map<int,int> m;
    int count = 1,temp;
    memset(ant,0,sizeof(ant));
    for(int i = 0;i < A;i ++)
    {
        scanf("%d",&temp);
        if(!m[temp])
        {
            m[temp] = count ++;
        }
        ant[m[temp]] ++;
    }
    
    memset(dp,0,sizeof(dp));

    dp[0][0] = dp[1][0] = 1;
    for(int i = 1;i <= count; i++)
    {
        for(int j = 1;j <= B; j ++)
        {
            if(j - 1 - ant[i] >= 0)
            {
                dp[i % 2][j] = (dp[(i + 1) % 2][j] + dp[i % 2][j - 1] - dp[(i + 1) % 2][j - 1 - ant[i]] + 1000000) % 1000000;
            }
            else
            {
                dp[i % 2][j] = (dp[(i + 1 ) % 2][j] + dp[i %  2][j - 1]) % 1000000;
            }
        }
    }
    int ans = 0;
    for(int i = S;i <= B; i ++ )
    {
        ans = (ans + dp[count % 2][i]) % 1000000;
    }
    printf("%d\n",ans);
}