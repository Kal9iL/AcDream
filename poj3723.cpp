/*************************************************************************
    > File Name: poj3723.cpp
    > Author: Kal-iL
    > Mail: guzhenxingai@163.com
    > Created Time: Wed 19 Jul 2017 04:56:48 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXE = 50000 + 10;
const int MAXV = 10000 + 10;

int f[MAXV * 2];
int n,m,r;

struct Edge
{
	int from,to,cost;
};

Edge edge[MAXE];

int cmp(Edge a,Edge  b)
{
	return a.cost > b.cost;
}

int find_f(int x)
{
	if(f[x] == -1)
		return x;
	return f[x] = find_f(f[x]);
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d%d%d",&n,&m,&r);
		int ans = 0;
		memset(f,-1,sizeof(f));
		for(int i = 0;i < r;i ++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			edge[i].from = a;
			edge[i].to = b + n;
			edge[i].cost = c;
		}
		sort(edge,edge + r,cmp);
		for(int i = 0;i < r;i ++)
		{
			int fx = find_f(edge[i].from);
			int fy = find_f(edge[i].to);
			if(fx == fy)
				continue;
			else
			{
				f[fx]  = fy;
				ans += edge[i].cost;
			}
		}
		printf("%d\n",10000 * (m + n) - ans);
	}
}
