#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 500 + 10;

int n,m;
long long mod;

long long dp[2][MAXN][MAXN];

char s[MAXN];
int count[MAXN];

void solve()
{
	for(int i = 0;i < n;i ++)
	{
		if(s[i] == '1')
		{
			count[i] ++;
		}
	}
}

int main()
{
	scanf("%d%d%lldd",&n,&m,&mod);
	memset(count,0,sizeof(count));
	for(int i = 0;i < m;i ++)
	{
		scanf("%s", s);
		solve();
	}
	int count1 = 0, count2 = 0; 
	for(int i = 0;i < n;i ++)
	{
		if(2 - count[i] == 1)
			count1 ++;
		if(2 - count[i] == 2)
			count2 ++;
	}
	//cout<<count1<<" "<<count2<<endl;
	memset(dp,0,sizeof(dp));
	dp[0][count1][count2] = 1;
	int now = 0;
	int next = 1;
	for(int i = 1; i <= n - m; i ++)
	{
		memset(dp[next],0,sizeof(dp[next]));
		for(int j = 0;j <= n; j ++)
		{
			for(int k = 0;k <= n; k ++)
			{
				if(!dp[now][j][k])
					continue;
				if(j - 2 >= 0)
					dp[next][j - 2][k] = (dp[next][j - 2][k] + (dp[now][j][k] * j * (j - 1) / 2 % mod)) %mod;
				if(k - 1 >= 0)
					dp[next][j][k - 1] = (dp[next][j][k - 1] + (dp[now][j][k] * j * k % mod)) % mod;
				if(k - 2 >= 0 && j + 2 <= n )
					dp[next][j + 2][k - 2] = ((dp[next][j + 2][k - 2] + (dp[now][j][k]) * k * (k - 1) / 2 % mod) ) %mod;
			}
			//printf("\n");
			// for(int j = 0;j <= n;j ++)
			// {
			// 	for(int k = 0; k <= n; k ++)
			// 	{
			// 		printf(" dp[%d][%d][%d] = %d ",i ,j,k,dp[next][j][k]);
			// 	}
			// 	printf("\n");
			// }
			// printf("\n");
		}
		now = !now;
		next = !next;
		//printf("\n");
	}
	//int ans = 0;
	//cout<<endl;
	// for(int i = 0; i <= n;i ++)
	// {
	// 	for(int j = 0; j <= n; j ++)
	// 	{
	// 		ans =(ans + dp[(n - m) % 2][i][j]) % mod;
	// 	}
	// }
	printf("%lld\n",dp[(n - m) % 2][0][0]);
	//printf("%d\n",ans);
}