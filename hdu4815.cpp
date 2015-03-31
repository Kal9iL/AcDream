#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 40000 + 10;

int num[50];
int t,n;
double p;
long long sum;
long long tot;
long long dp[MAXN];

int main()
{
	scanf("%d",&t); 	
	while(t --)
	{
		sum = 0;
		memset(dp,0,sizeof(dp));
		scanf("%d%lf",&n,&p);
		for(int i = 0;i < n;i ++)
		{
			scanf("%d",&num[i]); 
			sum += num[i];
		}
		long long al = 1LL << n;
		dp[0] = 1;
		sort(num,num + n);
		for(int i = 0;i < n;i ++)
		{
			for(int j = sum; j >= num[i];j --)
			{
				dp[j] += dp[j - num[i]];
			}
		}
		tot = 0;
		for(int i = 0; i <= sum; i ++)
		{
			tot += dp[i];
			if(1.0 * tot / al >= p)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
}