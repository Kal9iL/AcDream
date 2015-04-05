/****************************************************
   file name: zuidalianxuhe.cpp
   author: Kal-iL
   creat time: 2015年04月05日 星期日 14时34分34秒
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

const int MAXN = 10000 + 10;

int num[MAXN];

int main()
{
	int K;
	long long max_sum;
	while(scanf("%d",&K) && K)
	{
		max_sum = 0;
		long long sum = 0;
		int first;
		int last;
		int first_temp;
		int flag = 1;
		for(int i = 0;i < K ;i ++)
		{
			scanf("%d",&num[i]);
			if(num[i] >= 0)
				flag = 0;
			if(sum == 0)
			{				
				first_temp = num[i];
			}
			sum += num[i];
			if(sum > max_sum)
			{
				max_sum = sum;
				first = first_temp;
				last = num[i];
			}
			if(sum < 0)
			{
				sum = 0;
//				first_temp = num[i + 1];
			}
		}
		if(max_sum == 0)
		{
			if(flag)
				printf("%lld %d %d\n",max_sum,num[0],num[K - 1]);
			else
				printf("0 0 0\n");
		}
		else
			printf("%lld %d %d\n",max_sum,first,last);
	}
    return 0;
}
