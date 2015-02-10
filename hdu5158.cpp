/****************************************************
   file name: bc562a.cpp
   author: Kal-iL
   creat time: Sun 18 Jan 2015 09:13:39 PM CST
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

const int MAXN = 0;

int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		if(n >= m)
		{
			printf("%d\n",m - 1);
			continue;
		}
		int temp = m % n;
		printf("%d\n",(temp - 1 + n )% n);
	}
    return 0;
}
