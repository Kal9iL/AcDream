/****************************************************
   file name: hdu5163.cpp
   author: Kal-iL
   creat time: Fri 30 Jan 2015 12:59:04 PM CST
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

using namespace std;

const int MAXN = 100000 + 10;

int dis;
int x,y;
long long sum[MAXN];

int main()
{
	int t;
	int n,m;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d%d",&n,&m);
		memset(sum,0,sizeof(sum));
		for(int i = 2;i <= n;i ++)
		{
			scanf("%d",&dis);
			sum[i] = sum[i - 1] + dis;
		//	printf("sum[%d] = %lld ",i,sum[i]);
		}
		for(int i = 1;i <= m;i ++)
		{
			scanf("%d%d",&x,&y);
			int t = (i - 1 + n )% n + 1;
			long long ans = 0;
			if(t > x)
			{
				ans += sum[n] - sum[t] + sum[n] - sum[x];
				if(x > y)
				{
					ans += sum[x] - sum[y];
				}
				else
				{
					ans += sum[y] + sum[x];
				}
			}
			else
			{
				ans += sum[x] - sum[t];
				if(x > y)
				{
					ans += sum[n] - sum[x] + sum[n] - sum[y];
				}
				else
				{
					ans += sum[y] - sum[x];
				}
			}
			printf("%lld\n",ans);
		}
		
	}
    return 0;
}
