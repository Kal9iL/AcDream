//腾讯面试题 

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int mod = 1000000007;

int c[100 + 10][100 + 10];

typedef long long ll;

void combination()
{
    memset(c,0,sizeof(c));
    for(int i = 0; i <= 100; i ++)
    {
        c[i][0] = 1;
    }
    for(int i = 1;i <= 100; i ++)
    {
        for(int j = 1;j <= 100 ;j ++)
        {
            ll temp = (ll(c[i - 1][j]) +ll(c[i - 1][j - 1])) % mod;
            c[i][j] = temp;
        }
    }
}

int main()
{
    int K,A,X,B,Y;
    scanf("%d",&K);
    scanf("%d%d%d%d",&A,&X,&B,&Y);
    int ans =  0;
    combination();
    for(int i = 0;i <= X; i ++)
    {
        for(int j = 0 ;j <= Y ;j ++)
        {
            if(i * A + j * B == K)
            {
                ll temp = (ll (c[X][i]) * ll(c[Y][j]) )% mod;
                ans = (ans + temp) % mod;
            }
        }
    }
    printf("%d\n",ans);
}