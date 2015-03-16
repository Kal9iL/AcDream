#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int MAXN = 1000 + 10;
const int mod = 1000000007;

int n,r,k,m;

long long dp[MAXN][MAXN];
long long stirling[MAXN][MAXN];

void SL()
{
	memset(stirling,0,sizeof(stirling));
	for(int i = 1;i < MAXN; i ++)
	{
		stirling[i][1] = 1;
	}
	for(int i = 1;i < MAXN; i ++)
	{
		for(int j = 2; j < MAXN; j ++)
		{
			if(i < j)
				break;
			stirling[i][j] = (stirling[i - 1][j - 1] + (j * stirling[i - 1][j]) % mod) % mod;

		}
	}
	
}

long long query(int r,int m)
{
	long long temp = 0;
	for(int i = 1;i <= m;i ++)
		temp = (temp + stirling[r][i]) % mod;
	return temp;
}

long long DP(int n,int r)
{
	memset(dp,0,sizeof(dp));
	for(int i = 0;i <= n; i ++)
	{
		dp[i][0] = 1;
		dp[i][1] = i;
	}

	for(int i = 1; i <= n; i ++)
	{
		for(int j = 2;j <= r; j ++)
		{
			if(i < j)
			{
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = (dp[i - 1][j] + (i - k >= 0 ? dp[i - k][j - 1] : 0)) % mod;
		}
	}
	return dp[n][r];
}

int main()
{
	SL();
	while(~scanf("%d%d%d%d",&n,&r,&k,&m))
	{
		long long ans = DP(n,r) * query(r,m) % mod; 
		// for(int i = 1;i <= n; i ++)
		// {
		// 	for(int j = 0;j <= r; j ++)
		// 		cout << dp[i][j] << " ";
		// 	cout << endl;
		// }
		//cout << dp[3][2] << endl;
		printf("%lld\n",ans);
	}
}