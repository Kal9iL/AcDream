/****************************************************
   file name: hdu1506.cpp
   author: Kal-iL
   creat time: 2015年04月05日 星期日 15时37分11秒
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

#define LL long long

using namespace std;

const int MAXN = 100000 + 10;

int height[MAXN];
int l[MAXN],r[MAXN];

int main()
{
	int n;
   	while(~scanf("%d",&n),n)
   	{
   		for(int i = 1;i <= n; i ++)
   			scanf("%d",& height[i]);
   		for(int i = 1;i <=  n;i ++)
   		{
   			int temp = i - 1;
   			while(temp > 0 && height[temp] >= height[i])
   			{
   				temp = l[temp];
   			}
   			l[i] = temp;
   		}
   		for(int i = n + 1;i > 0; i --)
   		{
   			int temp = i + 1;
   			while(temp < n + 1 && height[temp] >= height[i])
   			{
   				temp = r[temp];
   			}
   			r[i] = temp;
   		}
   		long long max_are = -1;
   		for(int i = 1;i <= n;i ++)
   		{
   			if((long long)(r[i] - l[i] - 1) *(long long )height[i] > max_are)
   				max_are = (long long )(r[i] - l[i] - 1) * (long long) height[i]; 
   		}
   		printf("%lld\n",max_are);
   	}
   	return 0;
}