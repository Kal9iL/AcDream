/****************************************************
   file name: hdu5167.cpp
   author: Kal-iL
   creat time: Fri 06 Feb 2015 05:58:37 PM CST
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

const int MAXN = 47;

int fibo[MAXN];
map<long long,bool> mp;

void f()
{
	queue<long long > q;
	fibo[0] = 0;
	fibo[1] = 1;
	mp[0] = mp[1] = true;
	q.push(1);
	for(int i = 2;i < MAXN ;i ++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		mp[fibo[i]] = true;
		q.push(fibo[i]);
	}
	//int p = 0;
	while(!q.empty())
	{
		//cout << "p = " << p ++ << endl; 
		long long t = q.front();
		q.pop();
		for(int i = 2;i < MAXN;i ++)
		{
			long long tmp = t * fibo[i];
			if(tmp > (1e9 + 10))
				break;
			if(!mp[tmp])
			{
				mp[tmp] = true;
				q.push(tmp);
			}
		}
	}
}


int main()
{
	int t;
	int n;
	scanf("%d",&t);
	f();
	while(t --)
	{
		scanf("%d",&n);
		if(mp[1.0 * n])
			printf("Yes\n");
		else
			printf("No\n");
	}
    return 0;
}
