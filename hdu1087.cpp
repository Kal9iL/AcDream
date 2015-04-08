/****************************************************
   file name: hdu1087.cpp
   author: Kal-iL
   creat time: 2015年04月08日 星期三 18时02分19秒
***************************************************/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>

#define LL long long

using namespace std;

const int MAXN = 1000 + 10;
int num[MAXN];
LL dp[MAXN];
int n;

int main()
{
	while(~scanf("%d",&n),n)
	{
		memset(dp,0,sizeof(dp));
		for(int i = 0;i < n;i ++)
		{
			scanf("%d",&num[i]);
		}
		for(int i = 0;i < n;i ++)
		{
			dp[i] = num[i];
			for(int j = 0 ;j < i ;j ++)
			{
				if(num[i] > num[j])
				{
					if(dp[j] + num[i] > dp[i])
						dp[i] = dp[j] + num[i];
				}
			}
		}
		LL ans = -1;
		for(int i = 0;i < n;i ++)
		{
			if(ans < dp[i])
				ans = dp[i];
		}
		printf("%lld\n",ans);
	}
    return 0;
}
