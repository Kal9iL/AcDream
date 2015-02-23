#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <climits>

using namespace std;

const int MAXN = 100 + 10;

map<long long,int> mp;
long long val[MAXN];

int main()
{
	int N;
	long long temp;
	int iCase = 1;
	while(~scanf("%d",&N))
	{
		printf("Case #%d: ",iCase ++);
		mp.clear();
		memset(val,0,sizeof(val));
		int j = 0;
		for(int i = 0; i < N; i ++ )
		{
			scanf("%lld",&temp);
			if(!mp[temp])
				val[j ++] = temp;
			mp[temp] ++;
		}
		if(j == 1)
		{
			printf("-1\n");
			continue;
		}
		sort(val,val + j);
		long long ans = 0;
		for(int i = 0;i < j;i ++)
		{
			if((val[(i - 1 + j) % j] + val[i]) % INT_MAX == val[(i + 1) % j])
				ans += mp[val[i]];
		}
		printf("%lld\n",ans);
	}
}
