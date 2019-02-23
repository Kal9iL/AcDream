#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 1000000 + 10;

int L,P,N;
int fuel[MAXN];

priority_queue<int> q;

int main()
{
	scanf("%d",&N);
	for(int i = 0; i < N; i ++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		fuel[x] = y;
	}
	scanf("%d%d",&L,&P);
	int ans = 0;
	for(int i = 1;i < L ; i ++)
	{
		if(fuel[L - i] > 0)
		{
			q.push(fuel[L -i]);
		}
		P --;
		if(P <= 0)
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
	}
	printf("%d\n",ans);
}