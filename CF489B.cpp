/****************************************************
   file name: CF489B.cpp
   author: Kalis
   creat time: Wed 26 Nov 2014 10:06:35 PM CST
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

const int MAXN = 100 + 10;

int a[MAXN];
int b[MAXN];

int main()
{
	int n,m;
	int ans = 0;
	scanf("%d",&n);
	for(int i = 0;i < n;i ++)
	{
		scanf("%d",&a[i]);

	}
	sort(a,a + n);
	scanf("%d",&m);
	for(int i= 0;i < m;i ++)
	{
		scanf("%d",&b[i]);
	}
	sort(b,b + m);
	int j = 0;
	for(int i =0; i < n && j < m;)
	{
		if(abs(a[i] - b[j]) <= 1)
		{
			ans ++;
			j ++;
			i ++;
		}
		else
		{
			if(a[i] > b[j])
			{
				j ++;
			}
			else
			{
				i ++;
			}
		}
	}
	printf("%d\n",ans);


    return 0;
}
