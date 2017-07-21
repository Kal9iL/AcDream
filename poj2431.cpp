#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 1000000 + 10;

int n,L,P;
int d[MAXN];
priority_queue<int> q;

int main()
{
	scanf("%d",&n);
	int stop,amount;
	memset(d,0,sizeof(d));
	for(int i = 0;i < n;i ++)
	{
		scanf("%d%d",&stop,&amount);
		d[stop] = amount;
	}
	scanf("%d%d",&L,&P);
	int ans = 0;
	for(int i = L - 1;i >= 0;i --)
	{
		P --;
		if(P < 0)
		{
			if(!q.empty())
			{
				P += q.top();
				q.pop();
				ans ++;
			}
			else
			{
				ans = -1;
				break;
			}
		}
		if(d[i] > 0)
		{
			q.push(d[i]);
		}
	}
	printf("%d\n",ans);

}