/****************************************************
   file name: cf489d.cpp
   author: Kalis
   creat time: Mon 01 Dec 2014 02:27:15 PM CST
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

const int MAXN = 3000 + 10; 

int n,m;
vector<int> v[MAXN];
bool metrix[MAXN][MAXN];
int vis[MAXN];
//int count[MAXN];

int main()
{
	int s,e;
	scanf("%d%d",&n,&m);
	memset(metrix,false,sizeof(false));
	for(int i = 0;i < m; i ++)
	{
		scanf("%d%d",&s,&e);
		v[s].push_back(e);
		metrix[s][e] = true;
	}
	int ans = 0;
	for(int a = 1; a <= n; a ++)
	{
		for(int c = 1; c <= n; c ++)
		{
			int count = 0;
			if(a != c)
			{
				for(vector<int> :: iterator it = v[a].begin(); it != v[a].end() ;it ++)
				{
					if(metrix[*it][c])
					{
						count ++;
					}
				}
			}
			if(count >= 2)
			{
				ans += count * (count - 1) / 2;
			}
		}
	}
	printf("%d\n",ans);

    return 0;
}
