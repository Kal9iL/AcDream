#include <cstdio>
#include <iostream>
#include <climits>
#include <cstring>
#include <queue>

using namespace std;

const int MAXV = 5000 + 10;
const int MAXE = 100000 + 10;
const int INF = 1e9;

struct Edge
{
	int from,to,cost;
};

int n,r;
int dist[MAXV],res[MAXV],vis[MAXV];

Edge edge[MAXE * 2];

void bellmanford(int v0)
{
	for(int i = 0;i <= n;i ++)
	{
		dist[i] = INF;
	}

	dist[v0] = 0;
	while(true)
	{
		bool update = false;
		for(int i = 0;i < r * 2;i ++)
		{
			if(edge[i].cost + dist[edge[i].from] < dist[edge[i].to])
			{
				dist[edge[i].to] = edge[i].cost + dist[edge[i].from];
				update = true;
			}
		}
		if(!update)
			break;
	}
}



void solve(int v0)
{
	for(int i = 0;i <= n;i ++)
	{
		res[i] = INF;
	}
	for(int i = 0; i < r * 2;i ++)
	{
		if(edge[i].to == v0)
		{
			//printf("%d %d %d\n",edge[i].from,edge[i].to,edge[i].cost);
			res[v0] = min(res[v0],dist[edge[i].from] + edge[i].cost); 
		}
	}

	// for(int i = 1;i <= n;i ++)
	// {
	// 	printf("%d ",res[i]);
	// }
	// printf("\n");

	int k = 6;
	while(k --)
	{
		bool update = false;
		for(int i = 0;i < r * 2;i ++)
		{
			if(edge[i].cost + dist[edge[i].from] < res[edge[i].to] || edge[i].cost + res[edge[i].from] < res[edge[i].to])
			{
				if(edge[i].cost + dist[edge[i].from] > dist[edge[i].to] && edge[i].cost + dist[edge[i].from] < res[edge[i].to])
				{
					res[edge[i].to] = edge[i].cost + dist[edge[i].from];
					update = true;
				}
				
				if(edge[i].cost + res[edge[i].from] > dist[edge[i].to] && edge[i].cost + res[edge[i].from] < res[edge[i].to])
				{
					res[edge[i].to] = edge[i].cost + res[edge[i].from];
					update = true;
				}
			}
		}
		// for(int i= 1;i <= n; i ++)
		// {
		// 	printf("%d ",res[i]);
		// }
		// cout << endl;
		if(!update)
			break;
	}
}
int main()
{
	scanf("%d%d",&n,&r);
	memset(edge,-1,sizeof(edge));
	for(int i = 0;i < r;i ++)
	{
		int a,b,d;
		scanf("%d%d%d",&a,&b,&d);
		edge[i].from = a;
		edge[i].to = b;
		edge[i].cost = d;
		edge[i + r].from = b;
		edge[i + r].to = a;
		edge[i + r].cost = d;
	}
	bellmanford(1);
	solve(1);
	//printf("%d\n",dist[n]);
	printf("%d\n",res[n]);

}
