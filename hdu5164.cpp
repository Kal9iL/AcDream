/****************************************************
   file name: hdu5164.cpp
   author: Kal-iL
   creat time: Fri 30 Jan 2015 01:57:36 PM CST
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

const int MAXN = 1000000 + 10;
map <int,int > next[MAXN];

int fail[MAXN];
int root = 1;
int l = 1;
int end[MAXN];

int seq[MAXN];
int mact[MAXN];

void init()
{
	for(int i = 0;i < MAXN; i ++)
	{
		next[i].clear();
	}
	memset(end,0,sizeof(end));
	memset(fail,0,sizeof(fail));
	memset(seq,0,sizeof(seq));
	memset(mact,0,sizeof(mact));
	l = 1;
}

void insert(int s[],int n)
{
	int now = root;
	for(int i = 0;i < n - 1;i ++)
	{
		if(next[now][s[i]] == 0)
		{
			next[now][s[i]] = ++l;
		}
		now = next[now][s[i]];
	}
	end[now] ++;
}

void build()
{
	queue<int> q;
	fail[root] = 0;
	map<int, int>::iterator it;
	for(it = next[root].begin();it != next[root].end();it ++)
	{
		int temp = it -> second;
		fail[temp] = root;
		q.push(temp);
	}

	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		end[now] += end[fail[now]];
		for(it = next[now].begin(); it != next[now].end();it ++)
		{
			int temp = it -> second;
			int fn = fail[now];
			int nxt = next[fn][it -> first];
			while(fn != 0 && !nxt)
			{
				fn = fail[fn];
				nxt = next[fn][it -> first];
			}
			if(fn)
			{
				fail[temp] = nxt;
			}
			else
				fail[temp] = root;
			q.push(temp);
		}
	}
}

int query(int s[],int n)
{
	int now = root;
	long long res = 0;
	for(int i = 0 ;i < n - 1;i ++)
	{ 
		int nxt = next[now][s[i]];
		while( now != 0 && !nxt)
		{
			now = fail[now];
			nxt = next[now][s[i]];
		}
		if(now != 0)
			now = nxt;
		else
			now = root;
		res += end[now];
	}
	return res;
}

int main()
{
	int t ,m,n,a,b,q;
	scanf("%d",&t);
	while(t --)
	{
		init();
		scanf("%d%d",&n,&m);
		for(int i = 0;i < n; i ++)
		{
			scanf("%d",&seq[i]);
		}
		for(int i = 0;i < n - 1; i ++)
		{
			int d = __gcd(seq[i],seq[i + 1]);
			seq[i] = seq[i] / d * 10001 + seq[i + 1] / d;
		}
		long long ans = 0;
		for(int i = 0;i < m;i ++)
		{
			scanf("%d",&q);
			for(int j = 0; j < q; j ++)
			{
				scanf("%d",&mact[j]);
			}
			for(int j = 0;j < q - 1; j ++)
			{
				int d = __gcd(mact[j],mact[j + 1]);
				mact[j] = mact[j] / d  * 10001 + mact[j + 1] / d;
			}
			if(q == 1)
			{
				ans += n;
				continue;
			}
			else
				insert(mact,q);
		}
		build();
		ans += query(seq,n);
		printf("%lld\n",ans);
	}
}