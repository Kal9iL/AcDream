/****************************************************
   file name: cf489e.cpp
   author: Kalis
   creat time: Wed 03 Dec 2014 01:12:58 PM CST
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

using namespace std;

const int MAXN = 1000 + 10;
int x[MAXN],b[MAXN];
double dp[MAXN];
int path[MAXN];
int ans[MAXN];
const double eps = 1e-10;
const double INF = 1e30;
int n,l;


bool yes(double R)
{
	memset(dp,0,sizeof(dp));
	for(int i = 1;i <= n; i ++)
	{
		dp[i] = INF;
		for(int j = 0; j < i; j ++)
		{
			double temp = dp[j] + sqrt(abs(x[i] - x[j]- l) + eps) - R * b[i] ;
			if(dp[i] > temp)
			{
				dp[i] = temp;
				path[i] = j;
			}
		}
	}
	return dp[n] > 0;
}

int main()
{
	scanf("%d %d",&n,&l);
	for(int i = 1; i <= n; i ++)
	{
		scanf("%d %d",&x[i],&b[i]);
	}
	double le = 0,ri = 1e30;
	double mid;
	while(abs(ri - le) > eps)
	{
		mid = (le + ri) / 2;
		if(yes(mid))
		{
			le = mid;
		}
		else
		{
			ri = mid;
		}
	}
	yes(le);
	int j = 0;
	for(int i = n ;i > 0;i = path[i])
	{
		ans[j ++] = i;
	}
	int flag = 1;
	for(int i = j - 1; i >= 0;i -- )
	{
		if(flag)
		{
			printf("%d",ans[i]);
			flag = 0;
		}
		else
		{

			printf(" %d",ans[i]);
		}
	}
	printf("\n");
    return 0;
}
