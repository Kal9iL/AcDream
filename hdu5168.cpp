/****************************************************
   file name: hdu5166.cpp
   author: Kal-iL
   creat time: Fri 06 Feb 2015 05:44:20 PM CST
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
const int INF = 0x0fffffff;
struct Edge
{
	int fr,to;
	long long wei;
};

Edge E[2 * MAXN];

struct Mes
{
	long long s,c;
	Mes()
	{
		s = c = 0;
	}
	Mes(long long _c, long long _s)
	{
		s = _s;
		c = _c;
	}
};

bool cmp1(Edge a,Edge b)
{
	return a.wei < b.wei;
}

bool cmp2(Mes a,Mes b)
{
	if(a.c == b.c)
		return a.s > b.s;
	return a.c < b.c;
}

vector<Mes> dp[MAXN];

void init()
{
	for(int i = 0;i < MAXN;i ++)
	{
		dp[i].clear();
	}
}

int main()
{
	int t, n, m, K;
	scanf("%d", &t);
	while(t --)
	{
		init();
		scanf("%d%d%d",&n,&m,&K);
		for(int i = 0;i < m;i ++)
		{
			scanf("%d%d%lld",&E[i].fr,&E[i].to,&E[i].wei);
		}
		sort(E,E + m,cmp1);
		for(int i = 0;i < m;i ++)
		{
			int fr = E[i].fr;
			int to = E[i].to;
			long long wei = E[i].wei;
			if(fr == 1)
			{
				if(dp[to].size() == 0)
				{
					dp[to].push_back(Mes(wei,wei));
				}
				else
				{
					if(dp[to][dp[to].size() - 1].s > wei)
						dp[to].push_back(Mes(wei,wei));
					
				}
			}
			else
			{
				if(dp[fr].size() == 0)
					continue;
				int p = upper_bound(dp[fr].begin(),dp[fr].end(),Mes(wei - K,-INF),cmp2) - dp[fr].begin();
				if(p == 0)
					continue;
				else
				{
					if(p > 0 && p < dp[fr].size())
					{
						p --;
					}
					else
					{
						if(dp[fr][dp[fr].size() - 1].c <= wei - K)
							p = dp[fr].size() - 1;
						else
							continue;
					}
				}
				if(dp[to].size() == 0)
					dp[to].push_back(Mes(wei,dp[fr][p].s + wei));
				else
					if(dp[to][dp[to].size() - 1].s > dp[fr][p].s + wei)
						dp[to].push_back(Mes(wei,dp[fr][p].s + wei));
			}
			
		}
		if(dp[n].size() == 0)
				printf("-1\n");
			else
				printf("%lld\n",dp[n][dp[n].size() - 1].s);
	}
}
