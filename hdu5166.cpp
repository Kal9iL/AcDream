/****************************************************
   file name: hdu5166.cpp
   author: Kal-iL
   creat time: Fri 06 Feb 2015 05:44:20 PM CST
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

const int MAXN = 1000 + 10;

int num;
int mp[MAXN];

int main()
{
	int t,n;
	scanf("%d",&t);
	while(t --)
	{
		memset(mp,0,sizeof(mp));
		scanf("%d",&n);
		for(int i = 0;i < n;i ++)
		{
			scanf("%d",&num);
			mp[num] = 1;
		}
		int flag = 1;
		for(int i = 1;i <= n + 2;i ++)
		{
			if(!mp[i])
			{
				if(flag)
				{
					printf("%d",i);
					flag = 0;
				}
				else
				{
					printf(" %d",i);
				}

			}
		}
		puts("");
	}
    return 0;
}
