#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n;

struct child
{
	int dis;
	int num;
	/* data */
};

child son[3];

bool mycamp(child a,child b)
{
	return a.dis > b.dis;
}
int main()
{
	int t	;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d",&n);
		for(int i = 0;i < n;i ++)
		{
			int max = -1;
			int temp = 0;
			for(int j = 0;j < 3 ;j ++)
			{
				scanf("%d",&temp);
				if(temp > max)
				{
					max = temp;
				}
			}
			son[i].dis = max;
			son[i].num = i;
		}
		int ans[3];
		sort(son,son + n,mycamp);
		for(int i = 0; i < n;i ++)
		{
			ans[son[i].num] = i;
		}
		for(int i = 0;i < n;i ++)
		{
			if(i)
				printf(" %d",ans[i] + 1);
			else
				printf("%d",ans[i] + 1);
		}
		printf("\n");
		// for(int i = 0;i < n;i ++)
		// {
		// 	int rank = 1;
		// 	for(int j = 0; j < n;j ++)
		// 	{
				
		// 		if(dis[i] < dis[j])
		// 		{
		// 			rank ++;
		// 		}
		// 	}
		// 	if(i)
		// 		printf(" %d", rank);
		// 	else
		// 		printf("%d",rank);

		// }
		// printf("\n");
	}
	
}