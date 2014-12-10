/****************************************************
   file name: cf489c.cpp
   author: Kalis
   creat time: Mon 01 Dec 2014 01:32:01 PM CST
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

int m,s;
char ansmax[MAXN],ansmin[MAXN];

void solvea() 
{
	memset(ansmax,0,sizeof(ansmax));
	int ts = s;
	for(int i = 0;i < m; i ++)
	{
		if(ts - 9 >= 0)
		{
			ansmax[i] = '0' + 9;
			ts = ts - 9;
		}
		else
		{
			ansmax[i] = ts +'0';
			ts = ts - ts;
		}
	}
}

void solvei()
{

	memset(ansmin,0,sizeof(ansmin));
	for(int i = 1;i <= 9;i ++)
	{
		if(s - i <= (m - 1) * 9)
		{
			ansmin[0] = i + '0';
			break;
		}
	}
	int ts = s - (ansmin[0] - '0');
	int tm = m - 1;
	for(int i = 1;i <= m - 2;i ++)
	{
		for(int j = 0;j <= 9; j ++)
		{
			if(ts - j <= (m - i - 1) * 9)
			{
				ansmin[i] = j + '0';
				ts -= j;
				break;
			}
		}
	}
	if(m > 1)
		ansmin[m - 1] = ts + '0';
}

int main()
{
	scanf("%d%d",&m,&s);
	if(m == 1 && s <= 9)
	{
		printf("%d %d\n",s,s);
		return 0;
	}
	if(s <= 0 || s > m * 9)
	{
		printf("-1 -1\n");

	}
	else
	{
		solvea();
		solvei();
		printf("%s %s\n",ansmin,ansmax);
	}
    return 0;
}
